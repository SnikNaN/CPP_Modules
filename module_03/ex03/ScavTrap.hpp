#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
protected:
	const static int _def_hit_points;
	const static int _def_energy_points;
	const static int _def_attack_damage;
	ScavTrap();
public:
	explicit ScavTrap(const std::string& name);
	virtual ~ScavTrap();
	ScavTrap& operator=(const ScavTrap& scav);
	ScavTrap(const ScavTrap& scav);

	void guardGate();
	void attack(const std::string& target);
};

#endif