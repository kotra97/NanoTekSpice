//
// Action.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:04 2017 Kotra
// Last update Sun Mar  5 05:09:50 2017 Kotra
//

#include <csignal>
#include <algorithm>
#include "Parser.hpp"

nts::Tristate CLOCK_STATE = nts::TRUE;

static bool stop;

bool compare(const t_output& first, const t_output& second)
{
  if (first.name < second.name)
    return true;
  else
    return false;
}

void Parser::display()
{
  sort(_output.begin(),_output.end(),compare);
  for (auto &it : _output)
  {
    if (it.state != nts::UNDEFINED)
      std::cout << it.name <<"=" << (int)it.state<<'\n';
    else
      std::cout << it.name <<"=U" <<'\n';
  }
  for (auto &it : _terminal)
    it->Compute(1);
}

void Parser::simulate(int i)
{
  if (i == 1)
    (CLOCK_STATE == nts::FALSE) ? (CLOCK_STATE = nts::TRUE) : (CLOCK_STATE = nts::FALSE);
  for (auto &it : _output)
    it.state = it.compo->Compute(1);
}

void Parser::dump()
{
  for (auto &it : _compo)
    it->Dump();
}

void stop_loop(int signal)
{
  (void)signal;
  stop = true;
}

void Parser::loop()
{
  stop = false;
  while (!stop)
  {
    std::signal(SIGINT, stop_loop);
    this->simulate();
    this->display();
  }
}

bool is_nbr(const std::string s)
{
  return (s.find_first_not_of( "01" ) == std::string::npos);
}

void Parser::SetInput(std::string line)
{
  std::string name;
  nts::Tristate value;

  if (line.find('=') == std::string::npos)
  {
    std::cerr << UKNW_INPUT << std::endl;
    return;
  }
  name = line.substr(0, line.find('='));
  line.erase(0, line.find('=') + 1);
  if (!is_nbr(line))
  {
    std::cerr << UKNW_INPUT << std::endl;
    return;
  }
  value = (nts::Tristate)stoul(line);
  for (auto &it : _input)
  {
    if (it->getName() == name)
    {
      it->SetInput(value);
      break;
    }
  }
  for (auto &it : _clock)
  {
    if (it->getName() == name)
    {
      (value == CLOCK_STATE) ? (value = nts::TRUE) : (value = nts::FALSE);
      it->SetInput(value);
      break;
    }
  }
}
