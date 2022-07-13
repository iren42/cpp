#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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
