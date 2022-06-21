#include "ClapTrap.hpp"

ClapTrap::ClapTrap():	_name("Nobody"), _hit_points(10),
						_energy_points(10), _attack_damage(0)
{
	std::cout << "*ClapTrap* default was created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "*ClapTrap* " << _name << " was destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
	_name = clap._name;
	_hit_points = clap._hit_points;
	_energy_points = clap._energy_points;
	_attack_damage = clap._attack_damage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &clap):	_name(clap._name),
											_hit_points(clap._hit_points),
											_energy_points(clap._energy_points),
											_attack_damage(clap._attack_damage)
{}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hit_points(10),
											_energy_points(10), _attack_damage(0)
{
	std::cout << "*ClapTrap* " << name << " was created" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points > 0)
	{
		if (_energy_points > 0)
		{
			std::cout << "*ClapTrap* " << _name << " attacks " << target;
			std::cout << ", causing " << _attack_damage << " points of damage!";
			std::cout << std::endl;
			_energy_points--;
		}
		else
		{
			std::cout << "Attack failed: *ClapTrap* " << _name;
			std::cout << "'s energy bar is empty! :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Attack failed: *ClapTrap* " << _name << " is dead" <<
			std::endl;
	}
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > amount)
	{
		std::cout << "*ClapTrap* " << _name << " take damage for " << amount;
		std::cout << " points" << std::endl;
		_hit_points -= amount;
	}
	else if (_hit_points > 0)
	{
		_hit_points = 0;
		std::cout << "*ClapTrap* " << _name << " lost all hit_points and was died" <<
			std::endl;
	}
	else
		std::cout << "*ClapTrap* " << _name << " was already died" << std::endl;
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0)
	{
		if (_energy_points > 0)
		{
			_energy_points--;
			_hit_points += amount;
			std::cout << "*ClapTrap* " << _name << " is repaired for " << amount;
			std::cout << " points!" << std::endl;
		}
		else
		{
			std::cout << "Repairing failed: *ClapTrap* " << _name;
			std::cout << "'s energy bar is empty! :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Repairing failed: *ClapTrap* " << _name << " is dead" <<
				  std::endl;
	}
	std::cout << "| hit: " << _hit_points;
	std::cout << " | energy: " << _energy_points;
	std::cout << " | attack: " << _attack_damage << " |" << std::endl;
}