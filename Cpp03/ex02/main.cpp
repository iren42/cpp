/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:37:02 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 21:25:16 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	int	i;
	ClapTrap	c;
	ScavTrap	s("Soupe");
	FragTrap	f("Fraise");

	c = s;
	i = 0;
	s.attack("Jenny");
	c.attack("Jenny");
	f.attack("Jenny");
	s.takeDamage(100); // c is out
	c.takeDamage(100); // c is out
	f.takeDamage(100); // c is out
	s.attack("Kyle"); // cannot attack
	c.attack("Kyle"); // cannot attack
	f.attack("Kyle"); // cannot attack
	s.beRepaired(100); // c full health
	c.beRepaired(100); // c full health
	f.beRepaired(100); // c full health
	i = 0;
	while (i < 10)
	{
		s.attack("Pikachu"); // attack Pikachu 5 times until out
		f.attack("Pikachu"); // attack Pikachu 5 times until out
		c.attack("Pikachu"); // attack Pikachu 5 times until out
		s.takeDamage(20);
		c.takeDamage(20);
		f.takeDamage(20);
		i++;
	}
	std::cout << std::endl;
	s.guardGate();
//	c.guardGate();
	f.highFivesGuys();
	s.beRepaired(1);
	c.beRepaired(1);
	f.beRepaired(1);
	i = 0;
	while (i < 100)
	{
		s.attack("Serpenta"); // attack Serpenta until out of energy
		c.attack("Serpenta"); // attack Serpenta until out of energy
		f.attack("Serpenta"); // attack Serpenta until out of energy
		i++;
	}

	s.guardGate();
	f.highFivesGuys();
}
