//
// all_chips.hpp for nano in /home/kotra/rendu/cpp_nanotekspice/include/
//
// Made by Kotra
// Login   <mathis.rousselot@epitech.eu@epitech.eu>
//
// Started on  Thu Mar  2 13:50:09 2017 Kotra
// Last update Sun Mar  5 04:11:13 2017 Kotra
//

#ifndef __CHIPS_HPP__
# define __CHIPS_HPP__

#include "IComponent.hpp"
#include "chipset.hpp"

class CTerminal : public chipset
{
public:
	CTerminal(std::string);
	~CTerminal();
	nts::Tristate Compute(size_t num);
private:
	nts::Tristate _oldClock;
	nts::IComponent *createTerminal(const std::string &value) const;
};

class C2716 : public chipset
{
public:
	C2716(std::string);
	~C2716();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create2716(const std::string &value) const;
	char _txt[2048];
};

class C4001 : public chipset
{
public:
	C4001(std::string);
	~C4001();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4001(const std::string &value) const;
};

class C4008 : public chipset
{
public:
	C4008(std::string);
	~C4008();
	nts::Tristate Compute(size_t num);
private:
	nts::Tristate _oldClock;
	nts::IComponent *create4008(const std::string &value) const;
};

class C4011 : public chipset
{
public:
	C4011(std::string);
	~C4011();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4011(const std::string &value) const;
};

class C4013 : public chipset
{
public:
	C4013(std::string);
	~C4013();
	nts::Tristate Compute(size_t num);
private:
	nts::Tristate _oldClockA;
	nts::Tristate _oldClockB;
	nts::IComponent *create4013(const std::string &value) const;
};

class C4030 : public chipset
{
public:
	C4030(std::string);
	~C4030();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4030(const std::string &value) const;
};

class C4040 : public chipset
{
public:
	C4040(std::string);
	~C4040();
	nts::Tristate Compute(size_t num);
private:
	nts::Tristate _oldClock;
	int _count;
	nts::IComponent *create4040(const std::string &value) const;
};

class C4069 : public chipset
{
public:
	C4069(std::string);
	~C4069();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4069(const std::string &value) const;
};

class C4071 : public chipset
{
public:
	C4071(std::string);
	~C4071();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4071(const std::string &value) const;
};

class C4081 : public chipset
{
public:
	C4081(std::string);
	~C4081();
	nts::Tristate Compute(size_t num);
private:
	nts::IComponent *create4081(const std::string &value) const;
};


#endif
