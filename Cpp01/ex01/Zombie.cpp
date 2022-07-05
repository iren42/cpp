/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:21:55 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 15:49:43 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::clog << "Zombie " << this->name << " destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": " << std::flush;
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
