//
// Pin.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:51 2017 Kotra
// Last update Thu Mar  2 13:50:54 2017 Kotra
//

#ifndef __PIN_HH__
# define __PIN_HH__

#include <iostream>
#include "IComponent.hpp"

class Pin
{
public:
	Pin(nts::Tristate = nts::UNDEFINED);
	~Pin(){};
	void						setValue(const nts::Tristate& state);
	nts::Tristate 	getValue(void) const;
	void						setUsed(const bool& used);
	bool 						getUsed(void) const;
private:
	nts::Tristate	_value;
	bool _used;
};

#endif
