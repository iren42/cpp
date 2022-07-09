/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 00:40:01 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//		std::cout << << std::endl;
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Copy assignment constructor called" << std::endl;
	WrongAnimal::operator=(other);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}
