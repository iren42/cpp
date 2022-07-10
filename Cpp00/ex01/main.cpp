/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:28:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 16:30:45 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "Enter a command: (ADD, SEARCH or EXIT)" << std::endl;
		getline(std::cin, input, '\n');
		std::cout << "Your input: " << input << std::endl;
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "Exit." << std::endl;	
			break ;
		}
		else
		{
			std::cout << input << std::endl;
			std::cout << "is not a valid command." << std::endl;
			std::cin.clear();
		}
		if (std::cin.eof())
		{
			std::cout << "Triggered EOF" << std::endl;
			std::cout << "Exit." << std::endl;	
			break ;
		}
#ifdef DEBUG
		std::cout << "End of main loop" << std::endl;
#endif
	}
	return (0);
}
