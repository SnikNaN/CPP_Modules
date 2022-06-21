#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Something");

	clap.attack("Somebody");
	clap.beRepaired(2);
	clap.takeDamage(5);
	clap.beRepaired(4);
	clap.beRepaired(4);
	clap.beRepaired(4);
	clap.beRepaired(4);
	//clap.takeDamage(30);
	clap.attack("S145");
	clap.attack("A5643");
	clap.beRepaired(4);
	clap.beRepaired(4);
	clap.beRepaired(4);
	clap.attack("A5643");
	clap.takeDamage(35);
	clap.takeDamage(3);

	return (0);
}
