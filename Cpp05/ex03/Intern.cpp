/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 10:11:40 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//		std::cout << << std::endl;
Intern::~Intern()
{
}

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(*this) = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

static Form	*createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string formName, const std::string formTarget)
{
	const std::string	forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	typedef Form*(*formFunc)(const std::string&);
	const formFunc forml[] = {
		&createRobotomyRequestForm,
		&createPresidentialPardonForm,
		&createShrubberyCreationForm
	};
	const int	formSize = sizeof(forms) / sizeof(*forms);
	int	i;

	i = 0;
	while (i < formSize)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			Form	*newForm = forml[i](formTarget);
			return (newForm);
		}
		i++;
	}
	std::cout << "Intern could not create " << formName << ". It does not exist." << std::endl;
	return (0);
}
