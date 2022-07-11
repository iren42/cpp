/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 15:16:06 by isabelle         ###   ########.fr       */
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
	i = 0;
	while (i < size)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	return (*this);
}
