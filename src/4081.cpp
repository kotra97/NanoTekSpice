//
// 4081.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:53:57 2017 Kotra
// Last update Sun Mar  5 04:41:05 2017 Kotra
//

#include "all_chips.hpp"

C4081::C4081(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 15; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
}

C4081::~C4081() {}

nts::Tristate C4081::Compute(size_t num)
{
	if (_pins[num].compo == NULL &&
		(num == 11 || num == 10 || num == 3 || num == 4))
	{
		std::cerr << "An output can't be linked" << std::endl;
		throw;
	}
	if (_pins[num].compo == NULL)
		return (_pins[num].state = nts::UNDEFINED);
	if (num != 11 && num != 10 && num != 3 && num != 4)
		return (_pins[num].state = CPTFROM(num));
	if (num == 11 || num == 4)
	{
		VALUEPIN(num + 1) = this->Compute(num + 1);
		VALUEPIN(num + 2) = this->Compute(num + 2);
		return (_pins[num].state = and_enum(VALUEPIN(num + 1), VALUEPIN(num + 2)));
	}
	if (num == 10 || num == 3)
	{
		VALUEPIN(num - 1) = this->Compute(num - 1);
		VALUEPIN(num - 2) = this->Compute(num - 2);
		return (_pins[num].state = and_enum(CPTFROM(num - 1), CPTFROM(num - 2)));
	}
	return (nts::UNDEFINED);
}
