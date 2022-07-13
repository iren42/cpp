/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 22:22:56 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


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
		Bureaucrat	sonia("Sonia", 1);
		Intern intern;
		Form *form1 = intern.makeForm("robotomy request", "Bender");
		Form *form2 = intern.makeForm("presidential pardon", "ChristopherOdd");
		Form *form3 = intern.makeForm("shrubbery creation", "my house");
		// sign and exec form1
		if (form1 != 0)
			std::cout << YEL << *form1 << RT << std::endl;
		sonia.signForm(*form1);
		// copy assign
		*form3 = *form1;
		if (form1 != 0)
			std::cout << YEL << *form1 << RT << std::endl;
		sonia.executeForm(*form1);
		// same thing as above but w/o console msg on top of that
		//	form1.beSigned(albert);
		//	form.execute(albert);

		std::cout << std::endl << std::endl;
		// sign and exec form2
		if (form2 != 0)
			std::cout << YEL << *form2 << RT << std::endl;
		sonia.signForm(*form2);
		if (form2 != 0)
			std::cout << YEL << *form2 << RT << std::endl;
		sonia.executeForm(*form2);


		std::cout << std::endl << std::endl;
		// exec form3
	//	if (form3 != 0)
	//		std::cout << YEL << *form3 << RT << std::endl;
	//	sonia.signForm(*form3);
		if (form3 != 0)
			std::cout << YEL << *form3 << RT << std::endl;
		sonia.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;

	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	// TEST 2: Intern tries to create a form that does not exist
	try
	{
		Intern	intern;

		Form *form  = intern.makeForm("Rental car", "iren");


		if (form != 0)
			std::cout << *form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}
