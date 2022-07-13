/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 19:43:58 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
# define RS   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YEL  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */


// std::cout << << std::endl;
int	main()
{
	// TEST 1: tout va bien
	try
	{
		Bureaucrat	albert("albert", 5);
		Form	form("Fiche de sante", 120, 50);
		Form	form1("Bulletin scolaire", 10, 50);

		std::cout << GREEN << albert << RS << std::endl;
		std::cout << YEL << form << RS << std::endl;
		std::cout << YEL << form1 << RS << std::endl;

		albert.signForm(form);
		albert.signForm(form1);
	//			form1.beSigned(albert); // same thing as above but w/o console msg on top of that
		std::cout << YEL << form << RS << std::endl;
		std::cout << YEL << form1 << std::endl << RS << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// TEST 2: Bureaucrat too low level to sign the form
	try
	{
		Bureaucrat	albert("albert", 5);
		Form	form("Fiche de sante", 4, 100);
		Form	form1("Accord entre deux entreprises", 2, 100);

		std::cout << GREEN << albert << RS << std::endl;
		std::cout << YEL << form << std::endl;
		std::cout << form1 << RS << std::endl;

		//form.beSigned(albert);
		albert.signForm(form);
		albert.signForm(form1);
		std::cout << YEL << form << std::endl;
		std::cout << form1 << RS << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout  << std::endl;
	std::cout  << std::endl;
	// TEST 3: Form has invalid grade 
	try
	{
		Form	f("petition", 50, 190);
		//	Form	f("petition", 190, 50);
		//	Form	f("petition", 0, 19);
		//	Form	f("petition", 19, 0);
		std::cout << YEL << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		//	Form	f("petition", 50, 190);
		Form	f("petition", 190, 50);
		//	Form	f("petition", 0, 19);
		//	Form	f("petition", 19, 0);
		std::cout << YEL << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		//	Form	f("petition", 50, 190);
		//	Form	f("petition", 190, 50);
		Form	f("petition", 0, 19);
		//	Form	f("petition", 19, 0);
		std::cout << YEL << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		//	Form	f("petition", 50, 190);
		//	Form	f("petition", 190, 50);
		//	Form	f("petition", 0, 19);
		Form	f("petition", 19, 0);
		std::cout << YEL << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
