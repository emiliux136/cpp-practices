#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n========== DIAMONDTRAP CHECKS ==========" << std::endl;

	DiamondTrap diamond("Neo");
	ClapTrap target("Target");

	std::cout << "\n--- Attribute values ---" << std::endl;
	std::cout << "HP: " << diamond.getPoints() << std::endl;
	std::cout << "Energy: " << diamond.getEnergy() << std::endl;
	std::cout << "Attack: " << diamond.getAttack() << std::endl;

	std::cout << "\n--- DiamondTrap uses ScavTrap attack ---" << std::endl;
	diamond.attack(target.getName());

	std::cout << "\n--- Special functions from both parents ---" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout << std::endl;

	std::cout << "\n[4] Name check + whoAmI" << std::endl;
	std::cout << "ClapTrap visible name via getName(): " << diamond.getName() << std::endl;
	diamond.whoAmI();

	std::cout << "\n--- Finishing Attribute values ---" << std::endl;
	std::cout << "HP: " << target.getPoints() << std::endl;
	std::cout << "Energy: " << target.getEnergy() << std::endl;
	std::cout << "Attack: " << target.getAttack() << std::endl;	

	std::cout << "\n========== GENERAL VALUES CHECKS ==========" << std::endl;

		ClapTrap clap("Clavo");
		ScavTrap scav("Escandalo");
		FragTrap frag("Furia");
		DiamondTrap dia("Diamante");

		std::cout << "\n--- Estados iniciales ---" << std::endl;
		std::cout << clap.getName() << "     HP: " << clap.getPoints() << ", ENRGY: " << clap.getEnergy() << ", DMG: " << clap.getAttack() << std::endl;
		std::cout << scav.getName() << " HP: " << scav.getPoints() << ", ENRGY: " << scav.getEnergy() << ", DMG: " << scav.getAttack() << std::endl;
		std::cout << frag.getName() << "     HP: " << frag.getPoints() << ", ENRGY: " << frag.getEnergy() << ", DMG: " << frag.getAttack() << std::endl;
		std::cout << dia.getName() << " HP: " << dia.getPoints() << ", ENERGY: " << dia.getEnergy() << ", DMG: " << dia.getAttack() << std::endl;

	std::cout << "\n========== END TEST ==========" << std::endl;
	return 0;
}