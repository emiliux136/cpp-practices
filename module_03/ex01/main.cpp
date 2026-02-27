#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n================== TESTING SCAVTRAP ==================\n\n";
	
	// Crear instancias de ScavTrap
	ScavTrap scav1("Paco");
	ScavTrap scav2("Pepe");
	ClapTrap clap1("Calvo");
	
	std::cout << "✓ ScavTrap instances created successfully (herencia de ClapTrap)\n\n";
	
	// Pruebas de ScavTrap (pruebas de herencia de ClapTrap)
	std::cout << "--- ScavTrap can use ClapTrap methods (Inheritance) ---\n";
	std::cout << "Name  : " << scav1.getName() << std::endl;
	std::cout << "Points: " << scav1.getPoints() << std::endl;
	std::cout << "Energy: " << scav1.getEnergy() << std::endl;
	std::cout << "Attack: " << scav1.getAttack() << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- ScavTrap attack() (inherited from ClapTrap) ---\n";
	scav1.attack(scav2.getName());
	std::cout << std::endl;
	
	std::cout << "--- ClapTrap attack() ---\n";
	clap1.attack(scav2.getName());
	std::cout << std::endl;

	std::cout << "--- ScavTrap takeDamage(10) (inherited from ClapTrap) ---\n";
	scav2.takeDamage(10);
	std::cout << "Points after damage: " << scav2.getPoints() << std::endl;
	std::cout << "Attack points after damage: " << scav2.getAttack() << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- ScavTrap beRepaired(5) (inherited from ClapTrap) ---\n";
	scav2.beRepaired(5);
	std::cout << "Points after repair: " << scav2.getPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- ScavTrap specific method: guardGate() ---\n";
	std::cout << "Guard Gate Status before: " << scav1.getStatus() << std::endl;
	scav1.guardGate();
	std::cout << "Guard Gate Status after: " << scav1.getStatus() << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- ScavTrap Copy Constructor ---\n";
	ScavTrap scav3(scav1);
	std::cout << "Copied ScavTrap name: " << scav3.getName() << std::endl;
	std::cout << std::endl;
	
	std::cout << "--- ScavTrap Assignment Operator ---\n";
	ScavTrap scav4("Empty");
	scav4 = scav1;
	std::cout << "Assigned ScavTrap name: " << scav4.getName() << std::endl;
	std::cout << std::endl;
	
	std::cout << "\n================== COMPREHENSIVE TEST ==================\n\n";
	
	std::cout << "--- Multiple interactions ---\n";
	ScavTrap Escandalo("Escandalo");
	ClapTrap Clavo("Clavo");
	
	std::cout << "Escandalo attacks Clavo: ---\n";
	Escandalo.attack(Clavo.getName());
	
	std::cout << "\nClavo takes 8 damage: ---\n";
	Clavo.takeDamage(8);
	std::cout << "Clavo HP: " << Clavo.getPoints() << std::endl;
	
	std::cout << "\nEscandalo activates guard gate: ---\n";
	Escandalo.guardGate();
	std::cout << "Guard Gate active: " << Escandalo.getStatus() << std::endl;
	
	std::cout << "\nClavo repairs 3 HP: ---\n";
	Clavo.beRepaired(3);
	std::cout << "Clavo HP: " << Clavo.getPoints() << std::endl;
	
	std::cout << "\n✓ All tests completed successfully!\n";

	return 0;
}