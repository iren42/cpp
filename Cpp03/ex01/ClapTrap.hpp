#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
//# define DEBUG

class ClapTrap
{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		virtual ~ClapTrap();
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator = (const ClapTrap &other);

		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif
