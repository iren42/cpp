/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:11:44 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//		std::cout << << std::endl;
Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
}


Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf" << std::endl;
}
