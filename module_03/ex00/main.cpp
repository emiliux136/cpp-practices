#include "ClapTrap.hpp"

int main()
{
  ClapTrap A("Paco");
  ClapTrap B("Pepe");
  A.attack(B.getName());
  A.takeDamage(2);
  B.takeDamage(9);
  B.beRepaired(22);
  B.attack("Tests");
  A.attack("Tests");
  std::cout << A.getName() << " has " << A.getPoints() << " points.\n";
  std::cout << B.getName() << " has " << B.getPoints() << " points.\n";
  A.attack(B.getName());
  return 0;
}