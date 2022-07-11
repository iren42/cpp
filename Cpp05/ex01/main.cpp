/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:35:24 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 20:58:18 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	// TEST 1: tout va bien
	try
	{
		Bureaucrat	albert("albert", 5);
		Form	form("Fiche de sante", 5);
		Form	form1("Bulletin scolaire", 10);

		std::cout << albert << std::endl;
		std::cout << form << std::endl;
		std::cout << form1 << std::endl;

		albert.signForm(form);
		albert.signForm(form1);
		//		form1.beSigned(albert); // same thing as above but w/o console msg on top of that
		std::cout << form << std::endl;
		std::cout << form1 << std::endl << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// TEST 2: Bureaucrat too low level to sign the form
	try
	{
		Bureaucrat	albert("albert", 5);
		Form	form("Fiche de sante", 4);
		Form	form1("Accord entre deux entreprises", 2);

		std::cout << albert << std::endl;
		std::cout << form << std::endl;
		std::cout << form1 << std::endl;

		//form.beSigned(albert);
		albert.signForm(form);
		albert.signForm(form1);
		std::cout << form << std::endl;
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
