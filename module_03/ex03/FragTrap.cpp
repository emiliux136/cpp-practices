#include "FragTrap.hpp"

//Orthodox canonical form.

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap: Default constructor called\n";
	this->Name = name;
	this->Points = 100;
	this->Energy = 100;
	this->Attack = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "FragTrap: Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "FragTrap: Copy constructor called\n";
	return (*this);
}

void FragTrap::highFivesGuys(void)
{

	std::cout << Name << ": High five people!";
}