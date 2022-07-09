/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:46:37 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 16:10:59 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
//#define DEBUG
FragTrap::~FragTrap() 
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->attackDamage = 30;
	this->hitPoints = 100;
	this->energyPoints = 100;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	(*this) = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment constructor called" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << GREEN << "FragTrap " << this->name << " dances with " << target << ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
		this->energyPoints--;
	}
#ifdef DEBUG
	std::cout << "FragTrap " << this->name << " has " << this->hitPoints << " hit points and " << this->energyPoints << " energy points now." << std::endl;
#endif
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " gives high five!" << std::endl;
}
