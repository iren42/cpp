/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:37:02 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 14:36:44 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	int	i;
	ScavTrap c("Lola");
	ClapTrap	original("Pompo");

	i = 0;
	c.attack("Jenny");
	original.attack("Jenny");
	c.takeDamage(1);
	c.attack("Jenny");
	c.takeDamage(100); // c is out
	c.attack("Kyle"); // cannot attack
	c.beRepaired(100); // c full health
	i = 0;
	while (i < 10)
	{
		c.attack("Pikachu"); // attack Pikachu 5 times until out
		c.takeDamage(20);
		i++;
	}
	std::cout << std::endl;
	c.guardGate();
	c.beRepaired(1);
	i = 0;
	while (i < 50)
	{
		c.attack("Serpenta"); // attack Serpenta until out of energy
		i++;
	}

	c.guardGate();
}
