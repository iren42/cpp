/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:47:30 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 17:22:14 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::clog << "HumanA " << this->name << " created" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::clog << "HumanA " << this->name << " destroyed" << std::endl;
}

// Functions
std::string	HumanA::getName()
{
	return (this->name);
}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << std::flush;
	std::cout << (this->weapon).getType() << std::endl;
}
