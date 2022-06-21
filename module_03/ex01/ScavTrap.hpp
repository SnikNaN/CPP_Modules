#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

class ScavTrap: public ClapTrap
{
private:
	ScavTrap();
public:
	explicit ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& scav);
	ScavTrap(const ScavTrap& scav);

	void guardGate();
	void attack(const std::string& target);
};

#endif