/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 23:38:02 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//		std::cout << << std::endl;
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
}


Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment constructor called" << std::endl;
	Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}
