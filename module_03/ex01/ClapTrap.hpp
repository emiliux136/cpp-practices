#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:						//its neccesary to put the atributes in protected mode,
	std::string Name;			// in order to use them as heritage in the scravtrap class
	int Points;
	int Energy;
	int Attack;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	std::string getName() const;
	int getPoints() const;
	int getEnergy() const;
	int getAttack() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
