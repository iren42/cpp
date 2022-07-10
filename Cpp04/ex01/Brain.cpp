/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 12:43:53 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//		std::cout << << std::endl;
Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy assignment constructor called" << std::endl;
	int	i;
	int	size;
	size = sizeof(other.ideas) / sizeof(*(other.ideas));


	//	std::cout << "Size array = " << size << std::endl;
	i = 0;
	while (i < size)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
//	this->ideas = other.ideas;
	return (*this);
}


