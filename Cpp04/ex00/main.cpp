/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 00:39:52 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	const WrongAnimal	*i1 = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << i1->getType() << " " << std::endl;
	i1->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	delete meta;
	delete i;
	delete i1;
	delete j;
	return (0);
}
