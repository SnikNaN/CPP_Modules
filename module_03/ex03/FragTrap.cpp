#include "FragTrap.hpp"

const int FragTrap::_def_hit_points = 100;
const int FragTrap::_def_energy_points = 100;
const int FragTrap::_def_attack_damage = 30;

FragTrap::FragTrap()
{
	std::cout << "*FragTrap* default was created" << std::endl;
	_name = "Nobody";
	_hit_points = _def_hit_points;
	_energy_points = _def_energy_points;
	_attack_damage = _def_attack_damage;
}

FragTrap::~FragTrap()
{
	std::cout << "*FragTrap* " << _name << " was destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag)
{
	_name = frag._name;
	_energy_points = frag._energy_points;
	_attack_damage = frag._attack_damage;
	_hit_points = frag._hit_points;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "*FragTrap* " << name << " was created" << std::endl;
	_name = name;
	_hit_points = _def_hit_points;
	_energy_points = _def_energy_points;
	_attack_damage = _def_attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap& scav)
{
	_name = scav._name;
	_hit_points = scav._hit_points;
	_energy_points = scav._energy_points;
	_attack_damage = scav._attack_damage;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (_hit_points > 0)
	{
		if (_energy_points > 0)
		{
			std::cout << "*FragTrap* " << _name << " attacks " << target;
			std::cout << ", causing " << _attack_damage << " points of damage!";
			std::cout << std::endl;
			_energy_points--;
		}
		else
		{
			std::cout << "Attack failed: *FragTrap* " << _name;
			std::cout << "'s energy bar is empty! :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Attack failed: *FragTrap* " << _name << " is dead" <<
				  std::endl;
	}
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "*FragTrap* " << _name << ": positive high five request!"
		<< std::endl;
}
