/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:51:09 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 17:23:20 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	// TESTS from the subject
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	
	// My tests
	std::cout << std::endl;
	std::cout << "IREN's TESTS" << std::endl;
	{
		Weapon bat = Weapon("baseball bat");

		HumanB jim("Jim");
		jim.attack();
		{
			jim.setWeapon(bat);
			jim.attack();

			// test with a weapon who will only exist inside current brackets
			Weapon noname = Weapon();
			jim.setWeapon(noname);
			jim.attack();
		}
		// print in console whatever garbage there is after noname is destroyed
		//		jim.attack();

		// NULL weapon
		Weapon	*ptr = NULL; 
		jim.setWeapon(ptr);
		jim.attack();

		// jim.setWeapon(NULL);
		//  does not work because NULL references can NOT exist. And if they do, UD
	}
	return (0);
}
