//
// terminal.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:54:38 2017 Kotra
// Last update Sun Mar  5 04:44:43 2017 Kotra
//

#include "all_chips.hpp"

#define NOUNDEF(x) ((x == -1 || x == 0) ? 0 : 1)

CTerminal::CTerminal(std::string info) : chipset(info)
{
	for (unsigned i = 1; i != 9; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
	_oldClock = nts::UNDEFINED;
}

CTerminal::~CTerminal() {}

nts::Tristate CTerminal::Compute(size_t num)
{
	(void)num;
	nts::Tristate addrBit[8] = {UPDATEPIN(1), UPDATEPIN(2), UPDATEPIN(3),
														UPDATEPIN(4), UPDATEPIN(5), UPDATEPIN(6),
														UPDATEPIN(7), UPDATEPIN(8)};
	char c = 0;

	for (int i = 7; i >= 0; i--)
		c = (c << 1) + NOUNDEF((int)addrBit[i]);
	if (_oldClock == nts::FALSE && CPTFROM(9) == nts::TRUE && num == 1)
		std::cout << c;
	_oldClock = CPTFROM(9);
	return (nts::UNDEFINED);
}
