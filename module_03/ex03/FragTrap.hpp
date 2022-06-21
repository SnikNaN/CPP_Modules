#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
protected:
	const static int _def_hit_points;
	const static int _def_energy_points;
	const static int _def_attack_damage;
	FragTrap();
public:
	explicit FragTrap(const std::string& name);
	virtual ~FragTrap();
	FragTrap& operator=(const FragTrap& frag);
	FragTrap(const FragTrap& frag);

	void attack(const std::string& target);
	void highFivesGuys();
};

#endif