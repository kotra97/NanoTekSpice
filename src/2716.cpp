//
// 2716.cpp for nano in /home/kotra/rendu/cpp_nanotekspice/src/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:49:54 2017 Kotra
// Last update Sun Mar  5 04:39:41 2017 Kotra
//

#include <fstream>
#include "all_chips.hpp"

#define NOUNDEF(x) ((x == -1 || x == 0 )? 0 : 1)

C2716::C2716(std::string info) : chipset(info)
{
	std::string flName;
	std::fstream  fs;

	for (unsigned i = 1; i != 25; ++i)
		_pins[i] = {NULL, -1, nts::UNDEFINED};
	if (info.find('(') == std::string::npos)
	{
		std::cerr << "No such file" << std::endl;
		throw;
	}
	info = info.substr(info.find('(') + 1);
	if (info.find(')') == std::string::npos)
	{
		std::cerr << "No such file" << std::endl;
		throw;
	}
	info = info.substr(0, info.find(')'));
	fs.open(info, std::iostream::in);
	if (!fs.is_open())
	{
		std::cerr << "No file" << std::endl;
		throw;
	}
	fs.read(_txt, 2048);
	fs.close();
}

C2716::~C2716() {}

nts::Tristate C2716::Compute(size_t num)
{
	nts::Tristate addrBit[11] = {UPDATEPIN(8), UPDATEPIN(7), UPDATEPIN(6),
														UPDATEPIN(5), UPDATEPIN(4), UPDATEPIN(3),
														UPDATEPIN(2), UPDATEPIN(1), UPDATEPIN(23),
														UPDATEPIN(22), UPDATEPIN(19)};
	int bitShift[9] = {0, 1, 2, -1, 3, 4, 5, 6, 7};
	int addrPos = 0;
	char c;

	for (int i = 10; i >= 0; i--)
		addrPos = (addrPos << 1) + NOUNDEF((int)addrBit[i]);
	if (UPDATEPIN(20) == nts::FALSE && UPDATEPIN(18) == nts::FALSE)
	{
		c = _txt[addrPos];
		if (num > 8 && num < 18 && num != 12)
			_pins[num].state = (nts::Tristate)(c >> bitShift[num - 9] & 1);
		if (num > 0 && num < 25)
			return (_pins[num].state);
	}
	if (num > 8 && num < 18 && num != 12)
		_pins[num].state = nts::FALSE;
	if (num > 0 && num < 25)
		return (_pins[num].state);
	return (nts::UNDEFINED);
}
