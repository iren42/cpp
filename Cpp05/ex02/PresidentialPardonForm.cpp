/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:03:04 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
//#define DEBUG

#define GRADE_EXEC_PP 5

PresidentialPardonForm::~PresidentialPardonForm()
{
#ifdef DEBUG
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25), target(target)
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
		this->target = other.target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() && executor.getGrade() <= GRADE_EXEC_PP)
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
	else if (!this->getIsSigned())
		throw (Form::GradeTooLowException("Exception: form is not signed"));
	else
		throw (Form::GradeTooLowException("Exception: grade is too low to execute"));
}
