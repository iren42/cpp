/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:16:05 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 12:06:47 by isabelle         ###   ########.fr       */
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

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "WrongAnimal and WrongCat example" << std::endl;
	const WrongAnimal	*wrongAnimal = new WrongCat();
	const WrongCat	*billie = new WrongCat();
	
	std::cout << wrongAnimal->getType() << " " << std::endl;
	wrongAnimal->makeSound();
	std::cout << billie->getType() << " " << std::endl;
	billie->makeSound();

	std::cout << std::endl;
	delete wrongAnimal;
	delete billie;

/*	std::cout << std::endl << "other examples" << std::endl;
	Cat	kitty;
	Dog	doggy;

	
	std::cout << std::endl;
	Animal &filou = kitty;
	std::cout << filou.getType() << " " << std::endl;
	filou.makeSound(); // "Miaou" because reference
	std::cout << std::endl;
	Animal	fila = kitty;
	std::cout << fila.getType() << " " << std::endl;
	fila.makeSound(); // "..."
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Animal	*p1 = new Dog(doggy); // copy constructor
	std::cout << std::endl;
	std::cout << p1->getType() << " " << std::endl;
	p1->makeSound();
	delete p1;

*/

	return (0);
}
