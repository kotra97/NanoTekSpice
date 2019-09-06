//
// terminal.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:38 2017 Kotra
// Last update Sun Mar  5 04:39:22 2017 Kotra
//

#include "all_chips.hpp"

#define NOUNDEF(x) ((x == -1 || x == 0) ? 0 : 1)

C4008::C4008(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 17; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
}

C4008::~C4008() {}

nts::Tristate C4008::Compute(size_t num)
{
	(void)num;
	nts::Tristate addrBitA[4] = {UPDATEPIN(7), UPDATEPIN(5),
															UPDATEPIN(3), UPDATEPIN(1)};
	nts::Tristate addrBitB[4] = {UPDATEPIN(6), UPDATEPIN(4),
															UPDATEPIN(2), UPDATEPIN(15)};
	int carry = NOUNDEF((int)UPDATEPIN(9));
	int res = 0;

	UPDATEPIN(8);
	UPDATEPIN(16);
	for (int i = 0; i < 4; i++)
	{
		res = NOUNDEF((int)addrBitA[i]) +
					NOUNDEF((int)addrBitB[i]) + carry;
		(res == 2 || res ==  3) ? (carry = 1) : (carry = 0);
		(res == 1 || res ==  3) ? (VALUEPIN(10 + i) = nts::TRUE) : (VALUEPIN(10 + i) = nts::FALSE);
	}
	(carry == 1) ? (VALUEPIN(14) = nts::TRUE) : (VALUEPIN(14) = nts::FALSE);
	if (num > 0 && num < 17)
		return (VALUEPIN(num));
	return (nts::UNDEFINED);
}
