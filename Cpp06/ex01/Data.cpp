/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/14 05:49:06 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//		std::cout << << std::endl;
Data::~Data()
{
	std::cout << "Data Destructor called" << std::endl;
}

Data::Data() : _num(0)
{
	std::cout << "Data Default constructor called" << std::endl;
}

Data::Data(int num) : _num(num)
{
	std::cout << "Data Default constructor called" << std::endl;
}


Data::Data(const Data &other)
{
	std::cout << "Data Copy constructor called" << std::endl;
	(*this) = other;
}

Data &Data::operator=(const Data &other)
{
	std::cout << "Data Copy assignment constructor called" << std::endl;
	if (this != &other)
		_num = other._num;
	return (*this);
}

void	Data::sing(void)
{
	std::cout << "Sha la~ la~ " << _num << std::endl;

}
