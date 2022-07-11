/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:51:16 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	// TEST 1: tout va bien
	try
	{
		Bureaucrat	albert("albert", 5);
		Bureaucrat	sonia("Sonia", 25);
		RobotomyRequestForm	form("Prince Charlot");
		PresidentialPardonForm	form1("Prisonner");
		ShrubberyCreationForm	form2("home");

		std::cout << albert << std::endl;
		std::cout << sonia << std::endl;

		sonia.signForm(form);
		sonia.signForm(form1);
		sonia.signForm(form2);
		//		form1.beSigned(albert); // same thing as above but w/o console msg on top of that
		form.execute(albert);
		form1.execute(albert);
		form2.execute(albert);

	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 2: Bureaucrat too low level to execute the signed form
	try
	{
		Bureaucrat	albert("Albert", 25);
		PresidentialPardonForm	form("Prisonner");

		std::cout << albert << std::endl;
		std::cout << form << std::endl;

		albert.signForm(form);
		form.execute(albert);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	// TEST 3: Bureaucrat cannot execute because unsigned form
	try
	{
		Bureaucrat	albert("CEO", 1);
		PresidentialPardonForm	form("Prisonner");

		std::cout << albert << std::endl;
		std::cout << form << std::endl;

		form.execute(albert);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}
