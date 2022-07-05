/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:28:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/02 21:28:16 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

using namespace std;

int	main()
{
	string	input;
	PhoneBook	pb;

	while (true)
	{
		cout << "Enter a command: (ADD, SEARCH or EXIT)" << endl;
		getline(cin, input, '\n');
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT" || cin.eof())
		{
			cout << "Exit." << endl;	
			break ;
		}
		else
		{
			cerr << input << flush;
			cerr << " is not a valid command." << endl;
		}
		if (cin.eof())
		{
			cout << "Triggered EOF" << endl;
			cout << "Exit." << endl;	
			break ;
		}
		cout << "End of main loop" << endl;
	}
}
