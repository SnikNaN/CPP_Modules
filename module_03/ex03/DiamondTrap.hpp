#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string	_name;
	DiamondTrap();

public:
	explicit DiamondTrap(const std::string& name);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& diamond);
	DiamondTrap(const DiamondTrap& diamond);

	void attack(const std::string& target);
	void whoAmI();
};

#endif