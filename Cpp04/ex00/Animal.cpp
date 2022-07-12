/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:10:56 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//		std::cout << << std::endl;
Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
	this->type = "unknown";
}


Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Copy assignment constructor called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}
