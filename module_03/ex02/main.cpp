#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("R2D2");
	frag.attack("Somebody");
	frag.beRepaired(2);
	frag.takeDamage(5);
	frag.takeDamage(10);
	frag.takeDamage(5);
	frag.beRepaired(4);
	frag.highFivesGuys();
	frag.attack("Aaaaa");

	return (0);
}
