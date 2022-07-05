/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:47:30 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 17:20:58 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	std::clog << "HumanB " << this->name << " created" << std::endl;
}

// Destructor
HumanB::~HumanB()
{
	std::clog << "HumanB " << this->name << " destroyed" << std::endl;
}

// Functions
std::string	HumanB::getName()
{
	return (this->name);
}

void	HumanB::attack()
{
	if (this->weapon == NULL)
	{
		std::cout << getName() << " cannot attack." << std::endl;
	}
	else
	{
		std::cout << getName() << " attacks with their " << std::flush;
		std::cout << (this->weapon)->getType() << std::endl;
	}
}

// used reference because in main.cpp, setWeapon(club);
void	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}

void	HumanB::setWeapon(Weapon *w)
{
	this->weapon = w;
}
