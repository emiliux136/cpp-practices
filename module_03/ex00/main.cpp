#include "ClapTrap.hpp"

int main()
{
  ClapTrap MachineA("Paco");
  ClapTrap MachineB("Pepe");
  MachineA.attack(MachineB.getName());
  MachineA.takeDamage(2);
  //MachineB.takeDamage(1000);
  MachineB.attack("Tests");
  MachineA.attack("Tests");
  MachineA.attack(MachineB.getName());
  return 0;
}