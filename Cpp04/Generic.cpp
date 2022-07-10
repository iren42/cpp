/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/09 23:08:29 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//		std::cout << << std::endl;
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->attackDamage = 0;
	this->name = "unknown";
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->attackDamage = 0;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
}


ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	(*this) = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment constructor called" << std::endl;
	this->attackDamage = other.attackDamage;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return (*this);
}


