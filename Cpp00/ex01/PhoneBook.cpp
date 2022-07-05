/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:39:58 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/02 22:11:53 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	isInputSpace(string str)
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

static string	getInfo(string text)
{
	string	input;

	while (true)
	{
		cout << text  << flush;
		getline(cin , input);
		if (cin.eof())
			return ("EOF");
		if (input != "" && !isInputSpace(input))
			break ;
		cerr << "Error: empty line" << endl;
	}
	return (input);
}

void	PhoneBook::add()
{
	string	input1;
	string	input2;
	string	input3;
	int		input4;
	string	input5;
	string	input;

	// Prompt the user for informations
	input1 = getInfo("First name: ");
	if (cin.eof())
		return ;
	input2 = getInfo("Last name: ");
	if (cin.eof())
		return ;
	input3 = getInfo("Nickname: ");
	if (cin.eof())
		return ;
	// Prompt the user until valid integer
	while (true)
	{	
		cout << "Phone number: " << flush;
		if (cin >> input4)
			break ;
		if (cin.eof())
			return ;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "Invalid input. Retry." << endl;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	input5 = getInfo("Darkest secret: ");
	if (cin.eof())
		return ;
	input = getInfo("Add this new contact in the phonebook? (y/!y) ");
	if (input == "y")
	{
		// Warning message for overwriting contacts
		if (this->nbContacts >= 8)
		{
			cout << "////////////////////////////////////////////" << endl;
			cout << "//////////////////WARNING///////////////////" << endl;
			cout << "////////////////////////////////////////////" << endl;
			cout << "Maximum number of contacts reached." << endl;
			cout << "Overwriting the oldest contact at each new addition." << endl;
			cout << "////////////////////////////////////////////" << endl;
		}
		// Set contact info
		c[this->nbContacts % 8].setFirstname(input1);
		c[this->nbContacts % 8].setLastname(input2);
		c[this->nbContacts % 8].setNickname(input3);
		c[this->nbContacts % 8].setSecret(input5);
		c[this->nbContacts % 8].setPhoneNumber(input4);
		cout << "New contact created!" << endl;
		this->nbContacts++;
	}
	else
		cout << "Cancelled contact addition" << endl;
}

// display a 10 characters-wide column for a string 
static void	displayColumn(string name)
{
	int	j;
	char	*s;

	j = 0;
	s = &name[0];
	while (j < 10)
	{
		if (j == 9 && j + 1 < (int)name.length())
			cout << "." << flush;
		else if (j < (int)name.length())
			cout << s[j] << flush;
		else
			cout << " " << flush;
		j++;
	}
}

// display a 10 characters-wide column for the index
static void	displayIndex(int n)
{
	int	i;

	i = 1;
	cout << n << flush;
	while (i < 10)
	{
		cout << " " << flush;
		i++;
	}
}

void	PhoneBook::search()
{
	int	i;
	int	input;

	i = 0;
	// Display saved contacts list
	cout << "Index     |Firstname |Lastname  |Nickname  " << endl;
	cout << "___________________________________________" << endl;
	while (i < 8)
	{
		displayIndex(i);	
		cout << "|" << flush;
		displayColumn(c[i].getFirstname());
		cout << "|" << flush;
		displayColumn(c[i].getLastname());
		cout << "|" << flush;
		displayColumn(c[i].getNickname());
		cout << endl;
		i++;
	}
	cout << "___________________________________________" << endl;

	// Prompt user to enter an index from the list
	if (this->nbContacts == 0)
		cout << "No contact to inquire." << endl;
	else
	{
		// Prompt the user until valid integer
		while (true)
		{	
			cout << "Enter the index of the contact to inquire: " << flush;
			if (cin >> input && (input >= 0 && input <= this->nbContacts - 1 && input <= 7))
				break ;
			if (cin.eof())
				return ;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "Invalid index. Retry." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// Display contact info
		cout << "*****" << endl;
		cout << "Contact information of entry " << input << endl;
		c[input].display();
		cout << "*****" << endl;
	}
}
