#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		~ScavTrap();
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator = (const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate(void);
};
#endif
