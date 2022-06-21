#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("R2D2");
	scav.attack("Somebody");
	scav.beRepaired(2);
	scav.takeDamage(5);
	scav.takeDamage(10);
	scav.takeDamage(5);
	scav.beRepaired(4);
	scav.guardGate();
	scav.attack("Bear");

	return (0);
}
