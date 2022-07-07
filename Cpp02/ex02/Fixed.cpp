/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:46:10 by iren              #+#    #+#             */
/*   Updated: 2022/07/07 11:27:59 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Destructor
Fixed::~Fixed()
{
#ifdef DEBUG
	std::cout << "Destructor called" << std::endl;
#endif
}

// Constructors
Fixed::Fixed()
{
#ifdef DEBUG
	std::cout << "Default constructor called" << std::endl;
#endif
	this->fixedPoint = 0;
}

Fixed::Fixed(const int input)
{
#ifdef DEBUG
	std::cout << "Int constructor called" << std::endl;
#endif
	this->fixedPoint = input << this->fracBits;
}

Fixed::Fixed(const float input)
{
#ifdef DEBUG
	std::cout << "Float constructor called" << std::endl;
#endif
	int	res;
	res = roundf(input * (1 << this->fracBits));
	this->fixedPoint = res;
}

// default behavior is to shallow copy (shared memory for pointers)
Fixed::Fixed(const Fixed &other)
{
#ifdef DEBUG
	std::cout << "Copy constructor called" << std::endl;
#endif
	*this = other; // to call the copy assignement operator 
}

// default behavior of the assignment operator is to copy the pointer location
Fixed &Fixed::operator=(const Fixed &rhs)
{
#ifdef DEBUG
	std::cout << "Copy assignment operator called" << std::endl;
#endif
	this->fixedPoint = rhs.fixedPoint;
	return (*this);
}

// prefix increment
Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

// postfix increment
Fixed Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();
	return (old);
}

// prefix decrement
Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

// postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed	old = *this;
	operator--();
	return (old);
}

// comparaison operators
int Fixed::operator<(const Fixed &other) const
{
	return (this->fixedPoint < other.fixedPoint);
}

int Fixed::operator<=(const Fixed &other) const
{
	return (this->fixedPoint <= other.fixedPoint);
}

int Fixed::operator>(const Fixed &other) const
{
	return (this->fixedPoint > other.fixedPoint);
}

int Fixed::operator>=(const Fixed &other) const
{
	return (this->fixedPoint >= other.fixedPoint);
}

int Fixed::operator==(const Fixed &other) const
{
	return (this->fixedPoint == other.fixedPoint);
}

int Fixed::operator!=(const Fixed &other) const
{
	return (this->fixedPoint != other.fixedPoint);
}

// Arithmetic operators

// addition
float Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed operator+(const Fixed &other, int ivalue)
{
	Fixed	o;

	o.setRawBits( other.getRawBits() + ivalue);
	return (o);
}

Fixed operator+(int value, const Fixed &rhs)
{
	Fixed	o;
	
	o.setRawBits(rhs.getRawBits() + value);
	return (o);
}

// substraction
float Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed operator-(const Fixed &other, int ivalue)
{
	Fixed	o;

	o.setRawBits( other.getRawBits() - ivalue);
	return (o);
}

Fixed operator-(int value, const Fixed &rhs)
{
	Fixed	o;
	
	o.setRawBits(rhs.getRawBits() - value);
	return (o);
}

// multiplication
float Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed operator*(const Fixed &other, int ivalue)
{
	Fixed	o;

	o.setRawBits( other.getRawBits() * ivalue);
	return (o);

}

Fixed operator*(int value, const Fixed &rhs)
{
	Fixed	o;

	o.setRawBits(rhs.getRawBits() + value);
	return (o);

}

// division
float Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed operator/(const Fixed &other, int ivalue)
{
	Fixed	o;

	if (ivalue == 0)
		return (0);
	o.setRawBits( other.getRawBits() / ivalue);
	return (o);
}

Fixed operator/(int value, const Fixed &rhs)
{
	Fixed	o;

	if (value == 0)
		return (0);
	o.setRawBits(rhs.getRawBits() / value);
	return (o);
}

// Member functions
int	Fixed::getRawBits(void) const
{
#ifdef DEBUG
	std::cout << "getRawBits member function called" << std::endl;
#endif
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
#ifdef DEBUG
	std::cout << "setRawBits member function called" << std::endl;
#endif
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

// returns a reference to the smallest one
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return ((Fixed&)f2);
	return ((Fixed&)f1);
}

// Free function
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    return (os << fixed.toFloat());
}
