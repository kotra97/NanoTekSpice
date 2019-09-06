//
// 4040.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:53:40 2017 Kotra
// Last update Sun Mar  5 04:28:33 2017 Kotra
//

#include "all_chips.hpp"

#define CLOCK_ID 10

C4013::C4013(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 15; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
	_oldClockA = nts::UNDEFINED;
	_oldClockB = nts::UNDEFINED;
}

C4013::~C4013() {}

nts::Tristate C4013::Compute(size_t num)
{
	if (UPDATEPIN(3) == nts::TRUE && _oldClockA == nts::FALSE)
	{
		VALUEPIN(1) = UPDATEPIN(5);
		VALUEPIN(2) = not_enum(VALUEPIN(1));
	}
	_oldClockA = VALUEPIN(3);
	if (UPDATEPIN(11) == nts::TRUE && _oldClockB == nts::FALSE)
	{
		VALUEPIN(13) = UPDATEPIN(9);
		VALUEPIN(12) = not_enum(VALUEPIN(13));
	}
	_oldClockB = VALUEPIN(11);
	for (int i = 4; i <= 10; i += 2)
		UPDATEPIN(i);
	if (VALUEPIN(6) == nts::TRUE || VALUEPIN(4)== nts::TRUE)
	{
		VALUEPIN(1) = VALUEPIN(6);
		VALUEPIN(2) = VALUEPIN(4);
	}
	if (VALUEPIN(8) == nts::TRUE || VALUEPIN(10) == nts::TRUE)
	{
		VALUEPIN(13) = VALUEPIN(8);
		VALUEPIN(12) = VALUEPIN(10);
	}
	if (num == 14 || num == 7)
		UPDATEPIN(num);
	if (num > 0 && num < 15)
		return (VALUEPIN(num));
	return (nts::UNDEFINED);
}
