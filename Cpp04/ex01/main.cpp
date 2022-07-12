/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 21:25:53 by iren             ###   ########.fr       */
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
	{	Cat	basic;

		std::cout << std::endl;
		{
			Cat	tmp = basic; // copy asignment constructor
		}
		std::cout << "-----------" << std::endl;
		{
			Cat	tmp(basic); // copy constructor
		}
	}
	// TEST 2 : copy assign with dynamic alloc
	std::cout << "===============" << std::endl;
	{	std::cout << std::endl;
		std::cout << std::endl;
		Dog	*dog = new Dog();
		std::cout << "-----------" << std::endl;
		Dog	*dog1 = new Dog();
		std::cout << "-----------" << std::endl;
		*dog1 = *dog;
		std::cout << std::endl;
		delete dog;
		delete dog1;
	}
	std::cout << std::endl;

	// half dogs, half cats array of animals
	std::cout << "===============" << std::endl;
	{
		Animal *animals[N];
		int	i;

		i = 0;
		while (i < N / 2)
		{
			animals[i] = new Dog();
			i++;
		}
		while (i < N)
		{
			animals[i] = new Cat();
			i++;
		}
		// makeSound() for all of them
		i = 0;
		while (i < N)
		{
			std::cout << "i = " << i << " " << animals[i]->getType() << " " << std::flush;
			animals[i]->makeSound();
			i++;
		}
		std::cout << "==" <<std::endl;
		// delete all animals
		i = 0;
		while (i < N)
		{
			delete animals[i];
			i++;
		}
	}

	return (0);
}
