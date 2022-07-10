/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:39:58 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 16:19:24 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Phonebook constructor" << std::endl;
	this->nbContacts = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

static int	isInputSpace(std::string str)
{
	int	i;
	char	*s;

	i = 0;
	s = &str[0];
	while (s[i])
	{
		if (!isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static std::string	getInfo(std::string text)
{
	std::string	input;

	while (true)
	{
		std::cout << text  << std::endl;
		getline(std::cin , input);
		if (std::cin.eof())
			return ("EOF");
		if (input != "" && !isInputSpace(input))
			break ;
		std::cout << "Error: empty line" << std::endl;
	}
	return (input);
}

void	PhoneBook::add()
{
	std::string			input1;
	std::string			input2;
	std::string			input3;
	unsigned long int	input4;
	std::string			input5;
	std::string			input;

	// Prompt the user for informations
	input1 = getInfo("First name: ");
	if (std::cin.eof())
		return ;
	std::cout << "Your input: " << input1 << std::endl;
	input2 = getInfo("Last name: ");
	if (std::cin.eof())
		return ;
	std::cout << "Your input: " << input2 << std::endl;
	input3 = getInfo("Nickname: ");
	if (std::cin.eof())
		return ;
	std::cout << "Your input: " << input3 << std::endl;
	// Prompt the user until valid integer
	while (true)
	{	
		std::cout << "Phone number: " << std::endl;
		if (std::cin >> input4)
			break ;
		if (std::cin.eof())
			return ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Retry." << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Your input: " << input4 << std::endl;
	input5 = getInfo("Darkest secret: ");
	if (std::cin.eof())
		return ;
	std::cout << "Your input: " << input5 << std::endl;
	// Warning message for overwriting contacts
	if (this->nbContacts >= 8)
	{
		std::cout << "////////////////////////////////////////////" << std::endl;
		std::cout << "//////////////////WARNING///////////////////" << std::endl;
		std::cout << "////////////////////////////////////////////" << std::endl;
		std::cout << "Maximum number of contacts reached." << std::endl;
		std::cout << "Overwriting the oldest contact at each new addition." << std::endl;
		std::cout << "////////////////////////////////////////////" << std::endl;
	}
	input = getInfo("Add this new contact in the phonebook? (y/!y) ");
	std::cout << "Your input: " << input << std::endl;
	if (input == "y")
	{
		// Set contact info
		c[this->nbContacts % 8].setFirstname(input1);
		c[this->nbContacts % 8].setLastname(input2);
		c[this->nbContacts % 8].setNickname(input3);
		c[this->nbContacts % 8].setSecret(input5);
		c[this->nbContacts % 8].setPhoneNumber(input4);
		std::cout << "New contact created!" << std::endl;
		this->nbContacts++;
	}
	else
		std::cout << "Cancelled contact addition" << std::endl;
}

// display a 10 characters-wide column for a std::string 
static void	displayColumn(std::string name)
{
	int	j;
	char	*s;

	j = 0;
	s = &name[0];
	while (j < 10)
	{
		if (j == 9 && j + 1 < (int)name.length())
			std::cout << "." << std::flush;
		else if (j < (int)name.length())
			std::cout << s[j] << std::flush;
		else
			std::cout << " " << std::flush;
		j++;
	}
}

// display a 10 characters-wide column for the index
static void	displayIndex(int n)
{
	int	i;

	i = 1;
	std::cout << n << std::flush;
	while (i < 10)
	{
		std::cout << " " << std::flush;
		i++;
	}
}

void	PhoneBook::search()
{
	int	i;
	int	input;

	i = 0;
	// Display saved contacts list
	std::cout << "Index     |Firstname |Lastname  |Nickname  " << std::endl;
	std::cout << "___________________________________________" << std::endl;
	while (i < 8)
	{
		displayIndex(i);	
		std::cout << "|" << std::flush;
		displayColumn(c[i].getFirstname());
		std::cout << "|" << std::flush;
		displayColumn(c[i].getLastname());
		std::cout << "|" << std::flush;
		displayColumn(c[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "___________________________________________" << std::endl;

	// Prompt user to enter an index from the list
	if (this->nbContacts == 0)
		std::cout << "No contact to inquire." << std::endl;
	else
	{
		// Prompt the user until valid integer
		while (true)
		{	
			std::cout << "Enter the index of the contact to inquire: " << std::endl;
			if (std::cin >> input && (input >= 0 && input <= this->nbContacts - 1 && input <= 7))
				break ;
			if (std::cin.eof())
				return ;
			std::cout << "Your input: " << input << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index. Retry." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Your input: " << input << std::endl;
		// Display contact info
		std::cout << "*****" << std::endl;
		std::cout << "Contact information of entry " << input << std::endl;
		c[input].display();
		std::cout << "*****" << std::endl;
	}
}
