#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	const static int _size = 4;
	AMateria* _slot[_size];
	std::string _name;
	static AMateria* _floor[100];
public:
	Character();
	virtual ~Character();
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	explicit Character(const std::string& name);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	static AMateria* search_the_floor();
	static void clean_floor();
};


#endif //CHARACTER_HPP
