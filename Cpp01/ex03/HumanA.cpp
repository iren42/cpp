/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:47:30 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 19:39:37 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA " << this->name << " created" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " destroyed" << std::endl;
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
