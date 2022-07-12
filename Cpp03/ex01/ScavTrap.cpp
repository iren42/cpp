/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:46:37 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 22:26:43 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	(*this) = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment constructor called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}


void	ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " shoots " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->name << " has no energy or no hit point left. It cannot attack." << std::endl;
#ifdef DEBUG
	std::cout << "ScavTrap " << this->name << " has " << this->hitPoints << " hit points and " << this->energyPoints << " energy points now." << std::endl;
#endif
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now in gate keeper mode." << std::endl;
}
