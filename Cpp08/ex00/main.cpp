/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:32:18 by iren              #+#    #+#             */
/*   Updated: 2022/07/15 11:24:49 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);

	std::list<int>	l;
	l.push_back(100);
	l.push_back(200);
	l.push_back(333);

	std::vector<int> empty;

	try
	{
		easyfind< std::vector<int> >(vect, 1) ; // looking for 1
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		vect.push_back(1);
		easyfind< std::vector<int> >(vect, 1) ; // looking for 1 again
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		easyfind<std::list<int> >(l, 100) ; // looking for 100
		easyfind<std::list<int> >(l, 200) ;
		easyfind<std::list<int> >(l, 333) ;
		easyfind<std::list<int> >(l, 4) ;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		easyfind< std::vector<int> >(empty, 1) ; // looking for 1
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}
