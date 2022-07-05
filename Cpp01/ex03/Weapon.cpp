/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:54:32 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 17:21:43 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors
Weapon::Weapon(std::string type)
{
	this->type = type;
	std::clog << "Weapon " << this->type << " created" << std::endl;
}

Weapon::Weapon()
{
	this->type = "whatever-they-could-grab weapon";
	std::clog << "Weapon " << this->type << " created" << std::endl;
}

// Destructor
Weapon::~Weapon()
{
	std::clog << "Weapon " << this->type << " destroyed" << std::endl;
}

// Functions
void	Weapon::setType(std::string newType)
{
	std::clog << "setType(): " << this->type << " to " << newType << std::endl;
	this->type = newType;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}
