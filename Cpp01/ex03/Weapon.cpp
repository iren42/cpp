/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:54:32 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 19:40:11 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors
Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon " << this->type << " created" << std::endl;
}

Weapon::Weapon()
{
	this->type = "whatever-they-could-grab weapon";
	std::cout << "Weapon " << this->type << " created" << std::endl;
}

// Destructor
Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

// Functions
void	Weapon::setType(std::string newType)
{
	std::cout << "setType(): " << this->type << " to " << newType << std::endl;
	this->type = newType;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}
