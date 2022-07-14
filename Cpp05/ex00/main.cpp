/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 23:06:02 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# define RT   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GR   "\033[32m"      /* Green */
# define YEL  "\033[33m"      /* Yellow */
int	main()
{
	// TEST 0: instantiate valid Bureaucrats
	try
	{
		//	Bureaucrat a("Too low", 170);
		Bureaucrat a("iren", 136);
		Bureaucrat b("iren42", 1);
		Bureaucrat c("iren43", 150);
		std::cout << GR << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << RT << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RT << std::endl;
	}

	std::cout << std::endl << std::endl;

	// TEST 1: instantiate a Bureaucrat with invalid grade
	try
	{
		//	Bureaucrat a("Too low", 170);
		Bureaucrat b("Too high", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RT << std::endl;
	}

	std::cout << std::endl << std::endl;
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
			std::cout << GR << albert << RT << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RT << std::endl;
	}

	std::cout << std::endl << std::endl;
	// TEST 3: decrement a Bureaucrat's grade until it is too low
	try
	{
		int	i;
		Bureaucrat	lola("Lola", 140);
		Bureaucrat	josia(lola);
		Bureaucrat	alex("Alex", 130);
		josia = alex;

		i = 0;
		std::cout << josia << std::endl;
		while (i < 30)
		{
			josia.downGrade();
			std::cout << GR << josia << RT << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RT << std::endl;
	}

	std::cout << std::endl << std::endl;
	// TEST 4: set a grade too high
	try
	{

		Bureaucrat	lola("Lola", 140);
		lola.setGrade(0);
		std::cout << GR << lola << RT <<  std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RT << std::endl;
	}
	return (0);
}
