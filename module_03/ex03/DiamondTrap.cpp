#include "DiamondTrap.hpp"

//Orthodox canonical form.

DiamondTrap::DiamondTrap(const std::string &Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)
{
	std::cout << "DiamondTrap: Default constructor called\n";
	this->Name = Name;
	this->ClapTrap::Name = Name + "_clap_name";
	Points = FragTrap::Points;
	Energy = ScavTrap::ScavEnergy;
	Attack = FragTrap::Attack;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap: Copy constructor called\n";
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.Name;
	this->DiamondTrap::Name = other.ClapTrap::Name;
	std::cout << "DiamondTrap: Copy assignment operator called\n";
	return (*this);
}

void DiamondTrap::whoAmI() 
{
  std::cout << "WhoAmI?\n I am a DiamondTrap Named " << DiamondTrap::Name << " and my parent ClapTrap name is " << ClapTrap::Name << std::endl;
}