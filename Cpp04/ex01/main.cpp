/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 15:15:27 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define N 20
int	main()
{
	Cat	basic;
	std::cout << std::endl;
	
	// deep copy test
	{
		Cat	tmp = basic; // copy asignment constructor
	}
	std::cout << std::endl;
	{
		Cat	tmp(basic); // copy constructor
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "42 TESTS" << std::endl;
	Animal *animals[N];
	int	i;

	// half dogs, half cats array of animals
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
		std::cout << animals[i]->getType() << " " << std::flush;
		animals[i]->makeSound();
		i++;
	}

	// delete all animals
	i = 0;
	while (i < N)
	{
		delete animals[i];
		i++;
	}
	return (0);
}
