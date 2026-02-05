#ifndef HUMANB_CPP
# define HUMANB_CPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* weapon;
	std::string name;
public:
	HumanB(const std::string& name);
	~HumanB();
    void attack() const;
	void setWeapon(Weapon& Weapon);
	void setName(std::string s);
	std::string getName();
	std::string getWeapon();
};

#endif