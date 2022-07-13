/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 22:30:38 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RT   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GR   "\033[32m"      /* Green */
# define YEL  "\033[33m"      /* Yellow */
# define BL    "\033[34m"      /* Blue */

int	main()
{
		srand((unsigned int)time(NULL));
	// TEST 1: tout va bien
	try
	{
		Bureaucrat	albert("albert", 5);
		Bureaucrat	sonia("Sonia", 25);
		RobotomyRequestForm	form("Prince Charlot");
		PresidentialPardonForm	form1("Prisonner");

		ShrubberyCreationForm	form2("home");

		std::cout << std::endl;
		std::cout << GR << albert << std::endl;
		std::cout << sonia << RT << std::endl;

		std::cout << YEL << form << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2  << RT << std::endl;
		std::cout << std::endl;
		sonia.signForm(form);
		sonia.signForm(form1);
		sonia.signForm(form2);
		std::cout << std::endl;
		std::cout << YEL << form << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << RT << std::endl;

		std::cout << std::endl;
		albert.executeForm(form);
		albert.executeForm(form1);
		albert.executeForm(form2);
		// same thing as above but w/o console msg on top of that
		//	form1.beSigned(albert);
		//	form.execute(albert);

	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << "====================================" << std::endl;
	std::cout << "====================================" << std::endl;

	// TEST 2: Bureaucrat too low level to execute the signed form
	try
	{
		Bureaucrat	albert("Albert", 25);
		PresidentialPardonForm	form("Prisonner");

		std::cout << GR << albert << RT << std::endl;
		std::cout << YEL << form << RT << std::endl;

		albert.signForm(form);
		std::cout << YEL << form << RT << std::endl;
		form.execute(albert);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << "====================================" << std::endl;
	std::cout << "====================================" << std::endl;
	// TEST 3: Bureaucrat cannot execute because unsigned form
	try
	{
		Bureaucrat	albert("CEO", 1);
		PresidentialPardonForm	form("Prisonner");

		std::cout << GR << albert << RT << std::endl;
		std::cout << YEL << form << RT << std::endl;

		form.execute(albert);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}
