//
// CompoPin.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:36 2017 Kotra
// Last update Sun Mar  5 04:37:46 2017 Kotra
//

#ifndef __COMPOPIN_HPP__
# define __COMPOPIN_HPP__

#include <iostream>
#include <string>
#include "IComponent.hpp"
#include "chipset.hpp"

class CInput : public chipset
{
public:
	CInput(std::string);
	~CInput(){};
	nts::Tristate Compute(size_t);
};

class COutput : public chipset
{
public:
	COutput(std::string);
	~COutput(){};
	nts::Tristate Compute(size_t pin = 1);
};

class CTrue : public chipset
{
public:
	CTrue(std::string);
	~CTrue(){};
	nts::Tristate Compute(size_t pin = 1);
};

class CFalse : public chipset
{
public:
	CFalse(std::string);
	~CFalse(){};
	nts::Tristate Compute(size_t pin = 1);
};

class CClock : public chipset
{
public:
	CClock(std::string);
	~CClock(){};
	nts::Tristate Compute(size_t pin = 1);
};

#endif
