#include "ScavTrap.hpp"

//Orthodox canonical form.

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default ScavTrap constructor called\n";
	this->Name = name;
	this->Points = 100;
	this->Energy = 50;
	this->Attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "Copy ScavTrap constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "Copy ScavTrap constructor called\n";
}
