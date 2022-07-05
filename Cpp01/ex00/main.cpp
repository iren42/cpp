/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:25:13 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/03 23:32:39 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *pFred = newZombie("Fred");
	pFred->announce();

	randomChump("Kate");
	randomChump("Jessie");

	pFred->announce();
	delete pFred;
}
