#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap *sometrap = new DiamondTrap("Dima");
	sometrap->attack("GG");
	delete sometrap;

	DiamondTrap	diamond("SA-5326");
	diamond.attack("Something");
	diamond.takeDamage(25);
	diamond.beRepaired(1000);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	return (0);
}
