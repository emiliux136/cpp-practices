#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap //call the clapTrap class to heritage its mettods and atributes.
{
	protected:
		bool GuardGateStatus;
		int ScavEnergy;
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		virtual ~ScavTrap();

		bool getStatus() const;
		virtual void attack(const std::string& target);
		void guardGate();
};

#endif