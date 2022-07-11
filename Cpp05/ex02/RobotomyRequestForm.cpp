/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:02:42 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
//#define DEBUG
#define GRADE_EXEC_RR 45

RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef DEBUG
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72), target(target)
{
#ifdef DEBUG
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
#endif

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other)
{
#ifdef DEBUG
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
#endif
	(*this) = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
#ifdef DEBUG
	std::cout << "RobotomyRequestForm Copy assignment constructor called" << std::endl;
#endif
	if (this != &other)
	{
		Form::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() && executor.getGrade() <= GRADE_EXEC_RR)
	{
		srand((unsigned int)time(NULL));
		if (std::rand() % 2)
			std::cout << "Drrr... " << this->target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
	else if (!this->getIsSigned())
		throw (Form::GradeTooLowException("Exception: form is not signed"));
	else
		throw (Form::GradeTooLowException("Exception: grade is too low to execute"));
}
