#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
	ClapTrap();
public:
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& clap);
	ClapTrap& operator=(const ClapTrap& clap);
	explicit ClapTrap(const std::string& name);
	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif