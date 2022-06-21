#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* bill = new Character("bill");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	bill->equip(tmp);
	tmp = src->createMateria("cure");
	bill->equip(tmp);
	bill->equip(src->createMateria("cure"));
	bill->equip(Character::search_the_floor());
	bill->equip(src->createMateria("cure"));
	bill->equip(src->createMateria("cure"));
	bill->equip(src->createMateria("fire"));

	ICharacter* bob = new Character("bob");
	ICharacter* sam = new Character("sam");

	bill->use(0, *bob);
	bill->use(1, *bob);
	Character copy = Character(*(Character*)bill);
	Character copy2 = copy;
	bill->unequip(0);
	bob->equip(Character::search_the_floor());
	bob->use(0, *bill);
	bill->equip(Character::search_the_floor());
	bill->unequip(1);
	bill->use(0, *bob);
	copy.use(0, *bob);
	copy.use(1, *bob);
	copy.unequip(0);
	copy.unequip(1);
	copy2.use(0, *sam);
	copy2.use(1, *sam);
	copy2.unequip(0);
	copy2.unequip(1);
	copy2.use(0, *sam);

	delete bob;
	delete sam;
	delete bill;
	delete src;
	Character::clean_floor();
	return 0;
}
