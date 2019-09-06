//
// Parser.cpp for component in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Tue Jan 24 14:31:32 2017 Kotra
// Last update Thu Mar  2 13:40:46 2017 Kotra
//

#include <algorithm>
#include "Parser.hpp"

static void    clear_string(std::string &str)
{
  int   curs;
  int   curs_2;

  curs = 0;
  if (str.find('#')!= std::string::npos)
    str.erase(str.find('#'));
  std::replace(str.begin(), str.end(), '\t', ' ');
  curs_2 = 0;
  while ((str[curs] == '\t' || str[curs] == ' ') && str[curs] != '\0')
    curs++;
  while (str[curs] != '\0')
    {
      while ((str[curs] == '\t' || str[curs] == ' ') && str[curs] != '\0')
	       curs++;
      if (curs != 0 && str[curs] != '\0')
      {
	      if ((str[curs - 1] == ' ' || str[curs - 1] == '\t') && str[curs] != '\0'
        && curs_2 != 0)
        {
              str[curs_2] = ' ';
              curs_2++;
        }
      }
      if (str[curs] != '\0')
	    {
        str[curs_2] = str[curs];
        curs_2++;
        curs++;
    }
  }
  str[curs_2] = '\0';
  str.erase(curs_2);
}

void Parser::check_arg_link(std::string type2, std::string type)
{
  std::string name;
  std::string name2;
  std::vector<std::string>::iterator i;
  nts::IComponent *tmp;
  nts::IComponent *tmp2;
  size_t pin1;
  size_t pin2;
  int curs;

  if (type2.find(':') == std::string::npos || type.find(':') == std::string::npos)
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
  name = type.substr(0, type.find(':'));
  type.erase(0, type.find(':') + 1);
  name2 = type2.substr(0, type2.find(':'));
  type2.erase(0, type2.find(':') + 1);
  i = _name.begin();
  curs = 0;
  while ((*i) != name && i != _name.end())
  {
    i++;
    curs++;
  }
  if (i == _name.end())
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
  tmp = _compo[curs];
  i = _name.begin();
  curs = 0;
  while ((*i) != name2 && i != _name.end())
  {
    i++;
    curs++;
  }
  if (i == _name.end())
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
  tmp2 = _compo[curs];
  pin1 = stoul(type);
  pin2 = stoul(type2);
  tmp2->SetLink(pin2, (*tmp),pin1);
  tmp->SetLink(pin1, (*tmp2),pin2);
}

void Parser::check_arg_chip(std::string name, std::string type)
{
  nts::IComponent *tmp;
  if (name.find(':') != std::string::npos || type.find(':') != std::string::npos)
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
  for (std::vector<std::string>::iterator i = _name.begin(); i != _name.end(); i++)
  {
    if ((*i) == name)
    {
      std::cerr << SAME_NAME << std::endl;
      throw;
    }
  }
  tmp = _manager.createComponent(type, name);
  _compo.push_back(tmp);
  if (type == "output")
    _output.push_back({tmp, nts::UNDEFINED, name});
  if (type == "input")
    _input.push_back(static_cast<chipset *>(tmp));
  if (type == "clock")
    _clock.push_back(static_cast<chipset *>(tmp));
  if (type == "terminal")
      _terminal.push_back(static_cast<chipset *>(tmp));
  if (name.find('(') != std::string::npos)
    name = name.substr(0, name.find('('));
  _name.push_back(name);
}

static int check_section(std::string line, int &state)
{
  if (line == ".chipsets:")
  {
    if (line.find(' ') != std::string::npos || state != -1)
    {
      std::cerr << BAD_FILE << std::endl;
      throw;
    }
    else
    {
      state = 0;
      return (true);
    }
  }
  if (line == ".links:")
  {
    if (line.find(' ') != std::string::npos || state == 1)
    {
      std::cerr << BAD_FILE << std::endl;
      throw;
    }
    if (state == -1)
    {
      std::cerr << NO_CHIP << std::endl;
      throw;
    }
    else if (state == 0)
    {
      state = 1;
      return (true);
    }
  }
  return (false);
}

void Parser::feed(std::string const &info)
{
  static int state = -1;
  std::string tmp;
  std::string line = info;
  clear_string(line);
  if (line[0] == '\0')
    return;
  if (check_section(line, state) == true)
    return;
  if (line.find(' ') == std::string::npos)
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }

  tmp = line.substr(0, line.find(' '));
  line.erase(0, line.find(' ') + 1);

  if (line.find(' ') != std::string::npos)
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
  if (state == 0)
    check_arg_chip(line, tmp);
  else if (state == 1)
    check_arg_link(line, tmp);
  else
  {
    std::cerr << BAD_FILE << std::endl;
    throw;
  }
}

Parser::Parser()
{}

Parser::~Parser()
{
  for (size_t i = 0; i < _compo.size(); i++)
    delete _compo[i];
}
