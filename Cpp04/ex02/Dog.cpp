/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 15:44:15 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//		std::cout << << std::endl;
Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete (this->brain);
}

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf" << std::endl;
}
