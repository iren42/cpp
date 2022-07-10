/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:10:56 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 16:17:49 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstname = "(empty)";
	this->lastname = "(empty)";
	this->nickname = "(empty)";
	this->phoneNumber = 0;
	this->secret = "(empty)";
}

Contact::~Contact()
{
//	std::cout << "Contact destroyed" << std::endl;
}

void	Contact::display()
{
	std::cout << "Firstname: " << this->firstname << std::endl;
	std::cout << "Lastname: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}

void	Contact::setFirstname(std::string newName)
{
	this->firstname = newName;
}

void	Contact::setLastname(std::string newName)
{
	this->lastname = newName;
}

void	Contact::setNickname(std::string newName)
{
	this->nickname = newName;
}

void	Contact::setSecret(std::string newSecret)
{
	this->secret = newSecret;
}

void	Contact::setPhoneNumber(unsigned long int newNb)
{
	this->phoneNumber = newNb;
}

std::string	Contact::getFirstname()
{
	return (this->firstname);
}

std::string	Contact::getLastname()
{
	return (this->lastname);
}

std::string	Contact::getNickname()
{
	return (this->nickname);
}

std::string	Contact::getSecret()
{
	return (this->secret);
}

unsigned long int	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
