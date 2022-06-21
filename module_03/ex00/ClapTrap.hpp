#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
	ClapTrap();
public:
	~ClapTrap();
	ClapTrap(const ClapTrap& clap);
	ClapTrap& operator=(const ClapTrap& clap);
	ClapTrap(const std::string& name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif