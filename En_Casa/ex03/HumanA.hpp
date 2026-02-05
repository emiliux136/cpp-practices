#ifndef HUMANA_CPP
# define HUMANA_CPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon& weapon;
	std::string name;
public:
	HumanA(const std::string& name, Weapon& Weapon);
	~HumanA();
	void attack() const;
	void setName(std::string s);
	std::string getName();
};

#endif
