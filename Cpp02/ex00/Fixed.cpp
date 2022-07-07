/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:46:10 by iren              #+#    #+#             */
/*   Updated: 2022/07/05 23:37:32 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_nb_value = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_nb_value = rhs.fp_nb_value;
}

// default behavior of all assignement operators is to copy the pointer location
/*
Fixed &Fixed::operator = (const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->fp_nb_value = rhs.fp_nb_value;
	return (*this);
}*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_nb_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_nb_value = raw;
}
