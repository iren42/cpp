#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		~FragTrap();
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator = (const FragTrap &other);

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};
#endif
