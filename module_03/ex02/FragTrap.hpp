#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

class FragTrap: public ClapTrap
{
private:
	FragTrap();
public:
	explicit FragTrap(const std::string& frag);
	~FragTrap();
	FragTrap& operator=(const FragTrap& frag);
	FragTrap(const FragTrap& frag);

	void attack(const std::string& target);
	void highFivesGuys();
};

#endif