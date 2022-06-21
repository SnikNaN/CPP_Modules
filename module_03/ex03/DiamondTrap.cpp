#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "*DiamondTrap* default was created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hit_points = FragTrap::_def_hit_points;
	_energy_points = ScavTrap::_def_energy_points;
	_attack_damage = FragTrap::_def_attack_damage;
	std::cout << "*DiamondTrap* " << name << " was created" << std::endl;
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "*DiamondTrap* name: " << _name << " *ClapTrap* name: "
		<< ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "*DiamondTrap* " << _name << " was destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	ClapTrap::_name = diamond.ClapTrap::_name;
	_name = diamond._name;
	_hit_points = diamond._hit_points;
	_energy_points = diamond._energy_points;
	_attack_damage = diamond._attack_damage;
	return (*this);
}
