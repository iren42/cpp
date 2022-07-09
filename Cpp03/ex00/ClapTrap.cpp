/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 23:04:20 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->attackDamage = 0;
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;
	this->attackDamage = 0;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	this->attackDamage = other.attackDamage;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy or no hit point left. It cannot attack." << std::endl;
#ifdef DEBUG
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points and " << this->energyPoints << " energy points now." << std::endl;
#endif
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0 && amount > 0)
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is already out of hit points. Cannot take more damage." << std::endl;
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
#ifdef DEBUG
	std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points now." << std::endl;
#endif
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " drank a healing potion. It gives back " << amount << " hit points." << std::endl;
		this->hitPoints += amount;
		std::cout << "Gulp. Total hit points is now at " << this->hitPoints << "." << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has " << this->energyPoints << " energy points. Does not have enough energy to drink a potion." << std::endl;
}

//		std::cout << << std::endl;
