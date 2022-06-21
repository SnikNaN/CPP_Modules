#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	const static int _size = 4;
	AMateria* _materias[_size];
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);

	void learnMateria(AMateria* new_materia);
	AMateria* createMateria(std::string const & type);
};


#endif //MATERIASOURCE_HPP
