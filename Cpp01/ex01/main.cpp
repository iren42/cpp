/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:50:43 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 13:07:49 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 10

void	announceAll(Zombie *pHorde)
{
	int	i;

	i = 0;
	while (i < N)
	{
		std::cout << "Zombie " << i << " " << std::flush;
		pHorde[i].announce();
		i++;
	}
	std::cout << std::endl;
}

int	main(void)
{
	Zombie	*pHorde;
   
	pHorde = zombieHorde(N, "Helen");
	announceAll(pHorde);
	pHorde[0].setName("Tamtam");
	pHorde[3].setName("Leo");
	pHorde[7].setName("Emma");
	announceAll(pHorde);
	delete [] pHorde;
}
