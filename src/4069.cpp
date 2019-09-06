//
// 4069.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:53:44 2017 Kotra
// Last update Sun Mar  5 04:40:42 2017 Kotra
//

#include "all_chips.hpp"

C4069::C4069(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 15; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
}

C4069::~C4069() {}

nts::Tristate not_state(nts::Tristate src)
{
	if (src == nts::TRUE)
    return (nts::FALSE);
	if (src == nts::FALSE)
    return (nts::TRUE);
	return (nts::UNDEFINED);
}

nts::Tristate C4069::Compute(size_t num)
{
	if (num == 1 || num == 3 || num == 5 ||
			num == 9 || num == 11 || num == 13)
			return (VALUEPIN(num) = CPTFROM(num));
	if (num < 7 && num > 0)
	{
		VALUEPIN(num - 1) = CPTFROM(num - 1);
		return (VALUEPIN(num) = not_state(VALUEPIN(num - 1)));
	}
	else if (num > 7 && num < 14)
	{
		VALUEPIN(num + 1) = CPTFROM(num + 1);
		return (VALUEPIN(num) = not_state(VALUEPIN(num + 1)));
	}
	return (nts::UNDEFINED);
}
