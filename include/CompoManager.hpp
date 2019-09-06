//
// CompoManager.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:30 2017 Kotra
// Last update Sun Mar  5 04:35:50 2017 Kotra
//

#ifndef __COMPOMANAGER_HPP__
# define __COMPOMANAGER_HPP__

#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Pin.hpp"
#include "CompoPin.hpp"
#include "all_chips.hpp"

class CompoManager
{
private:
  nts::IComponent *createInput(const std::string &value) const {nts::IComponent *tmp; return (tmp = new CInput(value));}
  nts::IComponent *createOutput(const std::string &value) const {nts::IComponent *tmp; return (tmp = new COutput(value));}
  nts::IComponent *createTerminal(const std::string &value) const {nts::IComponent *tmp; return (tmp = new CTerminal(value));}
  nts::IComponent *createTrue(const std::string &value) const {nts::IComponent *tmp; return (tmp = new CTrue(value));}
  nts::IComponent *createFalse(const std::string &value) const {nts::IComponent *tmp; return (tmp = new CFalse(value));}
  nts::IComponent *createClock(const std::string &value) const {nts::IComponent *tmp; return (tmp = new CClock(value));}
  nts::IComponent *create2716(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C2716(value));}
  nts::IComponent *create4001(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4001(value));}
  nts::IComponent *create4008(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4008(value));}
  nts::IComponent *create4011(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4011(value));}
  nts::IComponent *create4013(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4013(value));}
  nts::IComponent *create4030(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4030(value));}
  nts::IComponent *create4040(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4040(value));}
  nts::IComponent *create4069(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4069(value));}
  nts::IComponent *create4071(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4071(value));}
  nts::IComponent *create4081(const std::string &value) const {nts::IComponent *tmp; return (tmp = new C4081(value));}
protected:

public:
  CompoManager();
  ~CompoManager();
  nts::IComponent *createComponent(const std::string &type, const std::string &value);
};

#endif /* __CHIPSET_HPP__ */
