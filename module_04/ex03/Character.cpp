#include "Character.hpp"

AMateria* Character::_floor[100];

Character::Character():
	_name("Nobody")
{
	std::cout << "*Character* default constructor called" << std::endl;
	for (int i = 0; i < _size; i++)
		_slot[i] = NULL;
}

Character::~Character()
{
	std::cout << "*Character* \"" << _name << "\" destructor called" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		if (_slot[i] != NULL)
		{
			delete _slot[i];
			_slot[i] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (_slot[idx] != NULL)
		_slot[idx]->use(target);
	else
		std::cout << _name << ": slot *" << idx << "* is empty" << std::endl;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "can't find materia" << std::endl;
		return;
	}
	std::cout << _name << " equipping " << m->getType() << std::endl;
	for (int i = 0; i < _size; i++)
	{
		if (_slot[i] == NULL)
		{
			_slot[i] = m;
			std::cout << "equipped at slot " << i << std::endl;
			return;
		}
	}
	std::cout << _name << ": inventory is full" << std::endl;
	delete m;
}

Character::Character(const Character& copy):
	_name(copy._name)
{
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	_name = copy._name;
	for (int i = 0; i < _size; i++)
	{
		if (_slot[i] != NULL)
			delete _slot[i];
		if (copy._slot[i] != NULL)
			_slot[i] = copy._slot[i]->clone();
		else
			_slot[i] = NULL;
	}
	return (*this);
}

Character::Character(const std::string& name):
	_name(name)
{
	std::cout << "*Character* \"" << name << "\" constructor called" << std::endl;
	for (int i = 0; i < _size; i++)
		_slot[i] = NULL;
}

const std::string &Character::getName() const
{
	return (_name);
}

void Character::unequip(int idx)
{
	if (idx >= _size)
	{
		std::cout << _name << ": Error: " << idx << ": invalid slot index"
			<< std::endl;
		return;
	}
	if (_slot[idx] == NULL)
	{
		std::cout << _name << ": Error: slot " << idx << " is empty" << std::endl;
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = _slot[idx];
			_slot[idx] = NULL;
			std::cout << _name << " drops " << _floor[i]->getType()
				<< " materia from slot " << idx << " on the floor" << std::endl;
			return;
		}
	}
	std::cout << "floor is full :)" << std::endl;
}

AMateria *Character::search_the_floor()
{
	AMateria* res;

	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] != NULL)
		{
			res = _floor[i];
			_floor[i] = NULL;
			return (res);
		}
	}
	return (NULL);
}

void Character::clean_floor()
{
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] != NULL)
		{
			std::cout << "Floor: " << i << " delete" << std::endl;
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}
