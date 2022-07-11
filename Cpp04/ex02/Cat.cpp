/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 15:05:38 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//		std::cout << << std::endl;
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}


Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	std::cout << "Cat Copy assignment constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}
