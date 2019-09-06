//
// chipset.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:15 2017 Kotra
// Last update Sun Mar  5 04:32:35 2017 Kotra
//

#ifndef __CHIPSET_HPP__
# define __CHIPSET_HPP__

# include <iostream>
# include <map>
# include "IComponent.hpp"
# include "Pin.hpp"

# define UPDATEPIN(x) (updatePin(_pins[x]))
# define CPTFROM(x) (_pins[x].compo->Compute(_pins[x].pin))
# define VALUEPIN(x) (_pins[x].state)

enum Type
{
	INPUT,
	OUTPUT,
	CLOCK,
	TRUE,
	FALSE,
  CHIP
};

typedef struct s_pin
{
  nts::IComponent *compo;
  long pin;
	nts::Tristate state;
}t_pin;

nts::Tristate and_enum(nts::Tristate const a, nts::Tristate const b);
nts::Tristate or_enum(nts::Tristate const a, nts::Tristate const b);
nts::Tristate xor_enum(nts::Tristate const a, nts::Tristate const b);
nts::Tristate updatePin(t_pin &src);
nts::Tristate not_enum(nts::Tristate const a);

class chipset : public nts::IComponent
{
public:
 	chipset(std::string str);
  ~chipset();
	std::string getName()const{return _name;};
  void SetLink(size_t const pin_num_this, nts::IComponent &component, size_t const pin_num_target);
	void SetInput(nts::Tristate const value){_pins[1].state = value;};
	virtual void Dump(void) const;
	virtual nts::Tristate Compute(size_t const pin_num_this = 1){(void)pin_num_this;return (nts::UNDEFINED);};
protected:
  Type _type;
	std::string _name;
	std::map<int, t_pin>	_pins;
};

#endif /* __CHIPSET_HPP__ */
