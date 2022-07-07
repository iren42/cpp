/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:46:10 by iren              #+#    #+#             */
/*   Updated: 2022/07/06 18:26:01 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = input << this->fracBits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	int	res;
	res = roundf(input * (1 << this->fracBits));
	this->fixedPoint = res;
}

// default behavior is to shallow copy (shared memory for pointers)
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
\	*this = other; // to call the copy assignement operator 
}

// default behavior of the assignment operator is to copy the pointer location
Fixed &Fixed::operator = (const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = rhs.fixedPoint;
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Member functions
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	float	res;

	res = ((float)this->fixedPoint) / (1 << this->fracBits);
	return (res);
}

int		Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->fracBits);
}

// Free function
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    return (os << fixed.toFloat());
}
