/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:37:02 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 11:41:29 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	int	i;
	ClapTrap c;

	i = 0;
	c.attack("Jenny");
	c.takeDamage(1);
	c.takeDamage(20); // c is out
	c.attack("Kyle");
	c.beRepaired(1);
	i = 0;
	while (i < 10)
	{
		c.attack("Kyle"); // attack Kyle 8 times until 0 energy left
		i++;
	}
	c.beRepaired(1);
}
