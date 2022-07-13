/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 22:29:35 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
//#define DEBUG

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef DEBUG
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, target, 5)
{
#ifdef DEBUG
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
#endif

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other)
{
#ifdef DEBUG
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
#endif
	(*this) = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
#ifdef DEBUG
	std::cout << "PresidentialPardonForm Copy assignment constructor called" << std::endl;
#endif
	if (this != &other)
	{
		Form::operator=(other);
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		Form::execute(executor);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}
