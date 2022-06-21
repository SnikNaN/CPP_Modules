#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{}

ScavTrap::~ScavTrap()
{
	std::cout << "*ScavTrap* " << _name << " was destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav)
{
	_name = scav._name;
	_energy_points = scav._energy_points;
	_attack_damage = scav._attack_damage;
	_hit_points = scav._hit_points;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "*ScavTrap* " << name << " was created" << std::endl;
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& scav)
{
	_name = scav._name;
	_hit_points = scav._hit_points;
	_energy_points = scav._energy_points;
	_attack_damage = scav._attack_damage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit_points > 0)
	{
		if (_energy_points > 0)
		{
			std::cout << "*ScavTrap* " << _name << " attacks " << target;
			std::cout << ", causing " << _attack_damage << " points of damage!";
			std::cout << std::endl;
			_energy_points--;
		}
		else
		{
			std::cout << "Attack failed: *ScavTrap* " << _name;
			std::cout << "'s energy bar is empty! :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Attack failed: *ScavTrap* " << _name << " is dead" <<
				  std::endl;
	}
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "*ScavTrap* " << _name << " is now in GateKeeper mode" << std::endl;
}