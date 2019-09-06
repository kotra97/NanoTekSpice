//
// main.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:42:48 2017 Kotra
// Last update Sun Mar  5 04:43:34 2017 Kotra
//

#include <fstream>
#include "Parser.hpp"

void loop(Parser &pars)
{
  std::string line;

  pars.simulate(-1);
  pars.display();
  std::cout << "> ";
  if (getline(std::cin, line).eof())
    return;
  while (line != "exit")
  {
    if (line == "display")
      pars.display();
    else if (line == "simulate")
      pars.simulate();
    else if (line == "dump")
      pars.dump();
    else if (line == "loop")
      pars.loop();
    else if (line != "exit")
      pars.SetInput(line);
    std::cout << "> ";
    if (getline(std::cin, line).eof())
      break;
  }
}

int main(int ac, char **av)
{
  Parser pars;
  std::string line;
  std::fstream  fs;

  if (ac < 2)
  {
    std::cerr << "No file" << std::endl;
    throw;
  }
  fs.open(av[1], std::iostream::in);
  if (!fs.is_open())
  {
    std::cerr << "No file" << std::endl;
    throw;
  }
  while (getline(fs, line))
    pars.feed(line);
  fs.close();
  for (int i = 2; i < ac; i++)
    pars.SetInput(av[i]);
  loop(pars);
  return (0);
}
