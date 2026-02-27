#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\n===== PRUEBA DE CREACION / DESTRUCCION =====\n" << std::endl;
	{
		ClapTrap clap("Clavo");
		ScavTrap scav("Escandalo");
		FragTrap frag("Furia");

		std::cout << "\n--- Estados iniciales ---" << std::endl;
		std::cout << clap.getName() << "     HP: " << clap.getPoints() << ", ENRGY: " << clap.getEnergy() << ", DMG: " << clap.getAttack() << std::endl;
		std::cout << scav.getName() << " HP: " << scav.getPoints() << ", ENRGY: " << scav.getEnergy() << ", DMG: " << scav.getAttack() << std::endl;
		std::cout << frag.getName() << "     HP: " << frag.getPoints() << ", ENRGY: " << frag.getEnergy() << ", DMG: " << frag.getAttack() << std::endl;

		std::cout << "\n--- FragTrap pide un high five ---" << std::endl;
		frag.highFivesGuys();
		std::cout << std::endl;

		std::cout << "\n--- ScavTrap activa y desactiva Guard Gate ---" << std::endl;
		scav.guardGate();
		std::cout << "GuardGateStatus: " << scav.getStatus() << std::endl;
		scav.guardGate();
		std::cout << "GuardGateStatus: " << scav.getStatus() << std::endl;

		std::cout << "\n--- Interaccion entre objetos ---" << std::endl;
		scav.attack(clap.getName());
		clap.takeDamage(scav.getAttack());
		clap.beRepaired(5);

		frag.attack(scav.getName());
		scav.takeDamage(frag.getAttack());

		std::cout << "\n--- Estado final ---" << std::endl;
		std::cout << clap.getName() << "     HP: " << clap.getPoints() << ",  EN: " << clap.getEnergy() << std::endl;
		std::cout << scav.getName() << " HP: " << scav.getPoints() << ",  EN: " << scav.getEnergy() << std::endl;
		std::cout << frag.getName() << "     HP: " << frag.getPoints() << ", EN: " << frag.getEnergy() << std::endl;
		std::cout << "\n(Saliendo del bloque -> se ejecutan destructores en orden inverso)\n" << std::endl;
	}

	std::cout << "\n===== FIN DE LA PRUEBA =====" << std::endl;
	return 0;
}