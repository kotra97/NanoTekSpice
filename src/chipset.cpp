//
// chipset.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:09 2017 Kotra
// Last update Sun Mar  5 04:42:20 2017 Kotra
//

#include "chipset.hpp"

extern nts::Tristate CLOCK_STATE;

chipset::chipset(std::string str)
{
	str = str.substr(0, str.find('('));
	_name = str;
}

chipset::~chipset()
{
	_pins.clear();
}

void 	chipset::Dump(void) const
{
	int 	i = 1;
	t_pin tmp;

	std::cout << "====\t"<< _name << "\t===="<< '\n';
	while (i != (int)_pins.size() + 1)
	{
		tmp = _pins.at(i);
		std::cout << "Pin " << i << ": ";
		std::cout << "state "<< (int)tmp.state ;
		std::cout << " - Name :" << _name<<'\n';
		i++;
	}
	std::cout << std::endl;
}

void chipset::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
	_pins[pin_num_this].compo = &component;
	_pins[pin_num_this].pin = (long)pin_num_target;
}

nts::Tristate and_enum(nts::Tristate const a, nts::Tristate const b)
{
	if (a == nts::UNDEFINED)
	{
		if (b == nts::UNDEFINED ||  b == nts::TRUE)
			return (nts::UNDEFINED);
		return (nts::FALSE);
	}
	if (b == nts::UNDEFINED)
	{
		if (a == nts::UNDEFINED ||  a == nts::TRUE)
			return (nts::UNDEFINED);
		return (nts::FALSE);
	}
	if (a == nts::TRUE && b == nts::TRUE)
		return (nts::TRUE);
	return (nts::FALSE);
}

nts::Tristate or_enum(nts::Tristate const a, nts::Tristate const b)
{
	if (a == nts::UNDEFINED)
	{
		if (b == nts::UNDEFINED ||  b == nts::FALSE)
			return (nts::UNDEFINED);
		return (nts::TRUE);
	}
	if (b == nts::UNDEFINED)
	{
		if (a == nts::UNDEFINED ||  a == nts::FALSE)
			return (nts::UNDEFINED);
		return (nts::TRUE);
	}
	if (a == nts::TRUE || b == nts::TRUE)
		return (nts::TRUE);
	return (nts::FALSE);
}

nts::Tristate xor_enum(nts::Tristate const a, nts::Tristate const b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (a == nts::TRUE && b == nts::TRUE)
		return (nts::FALSE);
	if (a == nts::FALSE && b == nts::FALSE)
		return (nts::FALSE);
	return (nts::TRUE);
}

nts::Tristate not_enum(nts::Tristate const a)
{
	if (a == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (a == nts::TRUE)
		return (nts::FALSE);
	return (nts::TRUE);
}

nts::Tristate updatePin(t_pin &src)
{
	if (src.compo != NULL)
		src.state = src.compo->Compute(src.pin);
	else
		src.state = nts::UNDEFINED;
	return (src.state);
}
