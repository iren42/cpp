/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/15 03:53:18 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//		std::cout << << std::endl;
Span::~Span()
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other)
{
	(*this) = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_v.clear();
		_v = other._v;
	}
	return (*this);
}

// accessors ====================================
std::vector<int> Span::getVec()
{
	return (_v);
}

void	Span::addNumber(int n)
{
	if (_v.size() + 1 > _N)
		throw (Span::CustomException("N numbers already in stock"));
	_v.push_back(n);

}

void Span::setVec(std::vector<int> v)
{
	_v.clear();
	_v = v;
}

// member functions ===================================
int	Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw (Span::CustomException("size too low"));
	int	shortest;
	unsigned long	i = 1;
	std::sort(_v.begin(), _v.end());
	shortest = _v.at(1) - _v.at(0);
	while (i < _v.size() - 1)
	{
		if (_v.at(i + 1) - _v.at(i) < shortest)
			shortest = _v.at(i + 1) - _v.at(i);
		i++;
	}
	return (shortest);	
}

int	Span::longestSpan()
{
	if (_v.size() <= 1)
		throw (Span::CustomException("size too low"));
	std::sort(_v.begin(), _v.end());
	return (_v.at(_v.size() - 1) - _v.at(0));
}

void	Span::display()
{
	std::vector<int>::iterator it = _v.begin();
	unsigned long	i = 0;
	std::cout << "=====================" << std::endl;
	while (i < _v.size())
	{
		if (i % 4 == 0)
			std::cout << std::endl;
		std::cout << *it << "\t";
		advance(it, 1);
				
		i++;
	}
	std::cout << std::endl;
	std::cout << "=====================" << std::endl;
}

// THE only free function
std::vector<int>	range_add_with_rand(unsigned long size)
{
	std::vector<int> v1;
	for(unsigned long i = 0; i < size; i++)
	{
		v1.push_back(std::rand());
	}
	return(v1);
}

// Exception class
Span::CustomException::~CustomException() throw() {}

Span::CustomException::CustomException(std::string msg) : std::exception(), _msg(msg)
{
}

const char	*Span::CustomException::what() const throw ()
{
	const char	*s = &_msg[0];
	return (s);
}
