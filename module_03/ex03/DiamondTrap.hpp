#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public ClapTrap, public ScavTrap, public FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap(const std::string &Name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		using ScavTrap::attack;  //Use the ScavTrap attack function on DiamondTrap class objects.
		void whoAmI();
};

#endif