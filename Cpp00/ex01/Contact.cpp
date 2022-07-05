/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:10:56 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/02 15:15:13 by isabelle         ###   ########.fr       */
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
//	cout << "Contact destroyed" << endl;
}

void	Contact::display()
{
	cout << "Firstname: " << this->firstname << endl;
	cout << "Lastname: " << this->lastname << endl;
	cout << "Nickname: " << this->nickname << endl;
	cout << "Phone number: " << this->phoneNumber << endl;
	cout << "Darkest secret: " << this->secret << endl;
}

void	Contact::setFirstname(string newName)
{
	this->firstname = newName;
}

void	Contact::setLastname(string newName)
{
	this->lastname = newName;
}

void	Contact::setNickname(string newName)
{
	this->nickname = newName;
}

void	Contact::setSecret(string newSecret)
{
	this->secret = newSecret;
}

void	Contact::setPhoneNumber(int newNb)
{
	this->phoneNumber = newNb;
}

string	Contact::getFirstname()
{
	return (this->firstname);
}

string	Contact::getLastname()
{
	return (this->lastname);
}

string	Contact::getNickname()
{
	return (this->nickname);
}

string	Contact::getSecret()
{
	return (this->secret);
}

int	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
