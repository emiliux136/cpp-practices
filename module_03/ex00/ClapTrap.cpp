#include "ClapTrap.hpp"

//Orthodox canonical form.

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called\n";
	this->Name = name;
	this->Points = 10;
	this->Attack = 0;
	this->Energy = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "Copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();
	return(*this);
}

//Getters mettod.

int ClapTrap::getPoints() const
{
	return(this->Points);
}

int ClapTrap::getEnergy() const
{
	return(this->Energy);
}

int ClapTrap::getAttack() const
{
	return(this->Attack);
}

std::string ClapTrap::getName() const
{
	return(this->Name);
}

//Required functions.

void ClapTrap::attack(const std::string& target)
{
	if(!(this->getEnergy() > 0))
	{
		std::cout << this->getName() << " don't have energy points so it can't attack.\n";
		return ;
	}
	if(!(this->getPoints() > 0))
	{
		std::cout << this->getName() << " don't have attack points so it can't attack.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttack() << " points of damage. Energy: <" << this->getEnergy() << ">" <<std::endl;
	this->Energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->Points += (-(int(amount)));
	std::cout << this->getName() << ": DAMMIT I got a " << amount << " attack damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!(this->getEnergy() > 0))
	{
		std::cout << this->getName() << " don't have energy points so it can't be repaired.\n";
		return ;
	}
	if(!(this->getPoints() > 0))
	{
		std::cout << this->getName() << " don't have attack points so it can't be repaired.\n";
		return ;
	}
	this->Points += amount;
	this->Energy -= 1;
	std::cout << "ClapTrap " << this->getName() << " repairs itself so now has " << this->getPoints() << " hit points. Energy: <" << this->getEnergy() << ">" <<std::endl;
}
