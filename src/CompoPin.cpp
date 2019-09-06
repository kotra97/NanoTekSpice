//
// CompoPin.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:22 2017 Kotra
// Last update Sat Mar  4 13:37:49 2017 Kotra
//

#include "Parser.hpp"

extern nts::Tristate CLOCK_STATE;

CInput::CInput(std::string info) : chipset(info)
{
	_pins[1] = {NULL, -1, nts::UNDEFINED};
}

nts::Tristate CInput::Compute(size_t pin)
{
	if (_pins[pin].state == nts::UNDEFINED)
	{
		std::cerr << NO_INPUT << " " << _name <<'\n';
		throw;
	}
	return (_pins[pin].state);
}

COutput::COutput(std::string info) : chipset(info)
{
	_pins[1] = {NULL, -1, nts::UNDEFINED};
}

nts::Tristate COutput::Compute(size_t pin)
{
	if (_pins[pin].compo == NULL)
	{
		std::cerr << NO_LINK << '\n';
		throw;
	}
	VALUEPIN(pin) = CPTFROM(pin);
	return (_pins[pin].state);
}

CTrue::CTrue(std::string info) : chipset(info)
{
	_pins[1] = {NULL, -1, nts::TRUE};
}

nts::Tristate CTrue::Compute(size_t pin)
{
	return (_pins[pin].state);
}

CFalse::CFalse(std::string info) : chipset(info)
{
	_pins[1] = {NULL, -1, nts::FALSE};
}

nts::Tristate CFalse::Compute(size_t pin)
{
	return (_pins[pin].state);
}

CClock::CClock(std::string info) : chipset(info)
{
	_pins[1] = {NULL, -1, CLOCK_STATE};
}

nts::Tristate CClock::Compute(size_t pin)
{
	if (pin != 1)
		return (nts::UNDEFINED);
	if (_pins[pin].state == nts::TRUE)
		return (CLOCK_STATE);
	else if (CLOCK_STATE == nts::FALSE)
		return (nts::TRUE);
	return (nts::FALSE);
}
