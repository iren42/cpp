/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:37:07 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 13:08:05 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*pHorde;
	int		i;

	pHorde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		pHorde[i].setName(name);
		i++;
	}
	return (pHorde);
}
