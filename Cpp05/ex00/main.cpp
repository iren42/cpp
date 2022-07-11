/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 18:55:32 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	// TEST 1: instantiate a Bureaucrat with invalid grade
	try
	{
		//	Bureaucrat a("Too low", 170);
		Bureaucrat b("Too high", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// TEST 2: increment a Bureaucrat's grade until it is too high
	try
	{
		int	i;
		Bureaucrat	albert("albert", 5);

		i = 0;
		std::cout << albert << std::endl;
		while (i < 10)
		{
			albert.upGrade();
			std::cout << albert << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	// TEST 3: decrement a Bureaucrat's grade until it is too low
	try
	{
		int	i;
		Bureaucrat	josia("Josia", 140);

		i = 0;
		std::cout << josia << std::endl;
		while (i < 20)
		{
			josia.downGrade();
			std::cout << josia << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
