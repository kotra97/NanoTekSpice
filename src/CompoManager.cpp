//
// CompoManager.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:15 2017 Kotra
// Last update Sun Mar  5 04:42:44 2017 Kotra
//

#include "CompoManager.hpp"

CompoManager::CompoManager(){}
CompoManager::~CompoManager(){}

nts::IComponent *CompoManager::createComponent(const std::string &type, const std::string &value)
{
  typedef nts::IComponent *(CompoManager::*FUNC)(const std::string &)const;
  std::map<std::string, FUNC> lexi_chip;

  lexi_chip["input"] = &CompoManager::createInput;
  lexi_chip["output"] = &CompoManager::createOutput;
  lexi_chip["terminal"] = &CompoManager::createTerminal;
  lexi_chip["true"] = &CompoManager::createTrue;
  lexi_chip["false"] = &CompoManager::createFalse;
  lexi_chip["clock"] = &CompoManager::createClock;
  lexi_chip["2716"] = &CompoManager::create2716;
  lexi_chip["4001"] = &CompoManager::create4001;
  lexi_chip["4008"] = &CompoManager::create4008;
  lexi_chip["4011"] = &CompoManager::create4011;
  lexi_chip["4013"] = &CompoManager::create4013;
  lexi_chip["4030"] = &CompoManager::create4030;
  lexi_chip["4040"] = &CompoManager::create4040;
  lexi_chip["4069"] = &CompoManager::create4069;
  lexi_chip["4071"] = &CompoManager::create4071;
  lexi_chip["4081"] = &CompoManager::create4081;

  if (lexi_chip.find(type) != lexi_chip.end())
  {
    FUNC fc= lexi_chip[type];
    return ((this->*fc)(value));
  }
  std::cout << "can't find the chip" << '\n';
  throw;
}
