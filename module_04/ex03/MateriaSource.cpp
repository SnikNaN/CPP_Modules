#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < _size; i++)
		_materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "*MateriaSource* destructor called" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* new_materia)
{
	if (new_materia != NULL)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_materias[i] == NULL)
			{
				_materias[i] = new_materia;
				return;
			}
		}
	}
	std::cout << "Error: MateriaSource memory is full!" << std::endl;
	if (new_materia != NULL)
		delete new_materia;
	new_materia = NULL;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < _size; i++)
	{
		if (_materias[i] != NULL)
			if (_materias[i]->getType() == type)
				return (_materias[i]->clone());
	}
	std::cout << "Materia type \"" << type << "\" not found" << std::endl;
	return (NULL);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	for (int i = 0; i < _size; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
		if (copy._materias[i] != NULL)
			_materias[i] = copy._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}
