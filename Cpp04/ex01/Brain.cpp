/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 18:30:21 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//		std::cout << << std::endl;
Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
	const int	size = sizeof(this->ideas) / sizeof(*(this->ideas));
	int	i;

	i = 0;
	while (i < size)
	{
		std::cout << this->ideas[i] << " " << std::flush;
		i++;
	}
	std::cout << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	const std::string	ideas[] = {"A", "B", "C", "D", "E"};
	int	i;
	const int	size = sizeof(this->ideas) / sizeof(*(this->ideas));
	const int	listSize = sizeof(ideas) / sizeof(*(ideas));

	i = 0;
	while (i < size)
	{
		this->ideas[i] = ideas[std::rand() % listSize];
		i++;
	}
	i = 0;
	while (i < size)
	{
		std::cout << this->ideas[i] << " " << std::flush;
		i++;
	}
	std::cout << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		int	i;
		int	size;

		size = sizeof(other.ideas) / sizeof(*(other.ideas));
		i = 0;
		while (i < size)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}
