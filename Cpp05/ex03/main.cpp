/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 12:32:09 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	// TEST 1: tout va bien
	try
	{
		Bureaucrat	sonia("Sonia", 25);
		Intern intern;
		Form *form = intern.makeForm("robotomy request", "Bender");

		std::cout << *form << std::endl;

		sonia.signForm(*form);
		sonia.executeForm(*form);
		// same thing as above but w/o console msg on top of that
		//	form1.beSigned(albert);
		//	form.execute(albert);
		delete form;

	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// TEST 2: Intern tries to create a form that does not exist
	try
	{
		Intern	intern;

		Form *form = 0;
		form = intern.makeForm("Rental car", "iren");


		if (form != 0)
		std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}
