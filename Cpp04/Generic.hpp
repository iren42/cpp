#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
//# define DEBUG

class ClapTrap
{
	protected:

	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator = (const ClapTrap &other);


};

#endif
