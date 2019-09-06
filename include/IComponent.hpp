//
// IComponent.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:41 2017 Kotra
// Last update Sun Mar  5 04:37:41 2017 Kotra
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <iostream>

namespace nts
{
  enum Tristate
  {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
  };

  class IComponent
  {
  public:
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

    virtual void SetLink(size_t pin_num_this,
    nts::IComponent &component,
    size_t pin_num_target) = 0;

    virtual void Dump(void) const = 0;

    virtual ~IComponent(void) { }
 };
}

#endif // __ICOMPONENT_HPP__
