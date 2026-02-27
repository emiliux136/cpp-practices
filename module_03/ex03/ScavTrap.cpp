#include "ScavTrap.hpp"

//Orthodox canonical form.

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap: Default constructor called\n";
	this->Name = name;
	this->Points = 100;
	this->Energy = 50;
	this->Attack = 20;
	ScavEnergy = 50;
	this->GuardGateStatus = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "ScavTrap: Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->Points = other.getPoints();
	this->Attack = other.getAttack();
	this->Energy = other.getEnergy();
	this->Name = other.getName();	
	std::cout << "ScavTrap: Copy constructor called\n";
	return (*this);
}

//getters mettods.

bool ScavTrap::getStatus() const
{
	return(this->GuardGateStatus);
}

//Required functions.

void ScavTrap::attack(const std::string& target)
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
	this->Energy -= 1;
	std::cout << "PUNCH ScavTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttack() << " points of damage." << std::endl;
}

void ScavTrap::guardGate()
{
	if(getStatus() == true)
	{
		this->GuardGateStatus = false;
		std::cout << "ScavTrap: Gate Keeping mode OFF\n";
	}
	else
	{
		this->GuardGateStatus = true;
		std::cout << "ScavTrap: Gate Keeping mode ON\n";
	}
}