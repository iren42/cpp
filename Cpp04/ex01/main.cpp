/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 15:53:11 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define N 6
int	main()
{
	srand((unsigned int)time(NULL));
	// TEST 1 : test du sujet. Copy and copy assign
	std::cout << "======== TEST 1 =======" << std::endl;
	{	
		std::cout << "----- Creating two Cat ------" << std::endl;
		Cat	basic1;
		std::cout << std::endl;
		Cat	basic2;
		std::cout << std::endl;
		{
			std::cout << "----- Copy assignment Cat to Cat ------" << std::endl;
			Cat	tmp = basic1; // copy asignment constructor
			std::cout << "----- Copy assignment Cat to Cat ------" << std::endl;
			tmp = basic2; // copy asignment constructor
			std::cout << std::endl;
		}
		std::cout  << std::endl;
		std::cout  << std::endl;
		{
			std::cout << "----- Copy Cat to Cat ------" << std::endl;
			Cat	tmp(basic1); // copy constructor
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
		// TEST 2 : copy assign with dynamic alloc
	{	
		std::cout << "======= TEST 2 ========" << std::endl;
		std::cout << "----- Creating a Dog ------" << std::endl;
		Dog	*dog2 = new Dog();
		std::cout << "----- Creating a Dog ------" << std::endl;
		Dog	*dog1 = new Dog();
		std::cout << "----- Creating a Dog ------" << std::endl;
		Dog	*dog3 = new Dog();
		std::cout << "----- Three dogs created ------" << std::endl;
		std::cout << "----- Copy assignment Dog to Dog 1------" << std::endl;
		*dog1 = *dog2;
		std::cout << "----- Copy assignment Dog to Dog 2------" << std::endl;
		*dog1 = *dog3;
		std::cout << std::endl;
		delete dog2;
		delete dog1;
		delete dog3;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// half dogs, half cats array of animals
	std::cout << "====== TEST 3 =========" << std::endl;
	{
		std::cout << "----- Creating an Animal array with half Dog and half Cat ------" << std::endl;
		Animal *animals[N];
		int	i;

		i = 0;
		while (i < N / 2)
		{
			animals[i] = new Dog();
			i++;
		}
		std::cout << std::endl;
		while (i < N)
		{
			animals[i] = new Cat();
			i++;
		}
		std::cout << "----- All Animal objects created ------" << std::endl;
		std::cout << "----- call function makeSound() for all Animal in the array ------" << std::endl;
		// makeSound() for all of them
		i = 0;
		while (i < N)
		{
			std::cout << "i = " << i << " " << animals[i]->getType() << " " << std::flush;
			animals[i]->makeSound();
			i++;
		}
		std::cout << "----- deleting the Animal array ------" << std::endl;
		// delete all animals
		i = 0;
		while (i < N)
		{
			delete animals[i];
			i++;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return (0);
}
