#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //call the clapTrap class to heritage its mettods and atributes.
{
	private:
		bool GuardGateStatus;
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		bool getStatus() const;
		void guardGate();
};

#endif