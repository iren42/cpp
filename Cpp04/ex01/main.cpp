/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 13:09:28 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int	main()
{
	Dog	basic;

	{
		Dog	tmp = basic;
	}
	Animal *animals[20];

	int	i;
	
	i = 0;
	while (i < 10)
	{
		animals[i] = new Dog();
		i++;
	}
	while (i < 20)
	{
		animals[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < 20)
	{
	std::cout << animals[i]->getType() << " " << std::endl;
	animals[i]->makeSound();
	i++;
	}

	i = 0;
	while (i < 20)
	{
		delete animals[i];
		i++;
	}

//	delete [] animals;
	return (0);
}
