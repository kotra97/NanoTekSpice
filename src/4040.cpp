//
// 4040.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:53:40 2017 Kotra
// Last update Sun Mar  5 04:40:30 2017 Kotra
//

#include "all_chips.hpp"

#define CLOCK_ID 10

C4040::C4040(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 17; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
	_oldClock = nts::UNDEFINED;
	_count = 0;
}

C4040::~C4040() {}

nts::Tristate C4040::Compute(size_t num)
{
	int prev_value[16] = {-1, 11, 5, 4, 6, 3,
												2, 1, -1, 0, -1, -1,
												8, 7, 9, 10};

	if (_oldClock == nts::TRUE && CPTFROM(10) == nts::FALSE)
		_count++;
	_oldClock = CPTFROM(10);
	if (CPTFROM(11) == nts::TRUE)
		_count = 0;
	VALUEPIN(11) = CPTFROM(11);
	VALUEPIN(10) = CPTFROM(10);
	if (num == 8 || num == 10 || num == 11 || num >= 16)
		return (VALUEPIN(num));
	VALUEPIN(num) = (nts::Tristate)(_count >> prev_value[num] & 1);
	return(VALUEPIN(num));
}
