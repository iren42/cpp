/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 19:32:20 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
//#define DEBUG

Form::~Form()
{
#ifdef DEBUG
	std::cout << "Form Destructor called" << std::endl;
#endif
}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(0)
{
#ifdef DEBUG
	std::cout << "Form Default constructor called" << std::endl;
#endif
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLowException());
	else if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form &other) : name(other.name), gradeSign(other.gradeSign), gradeExec(other.gradeExec), isSigned(other.isSigned)
{
#ifdef DEBUG
	std::cout << "Form Copy constructor called" << std::endl;
#endif
}

Form &Form::operator=(const Form &other)
{
#ifdef DEBUG
	std::cout << "Form Copy assignment constructor called" << std::endl;
#endif
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	return (os << rhs.getName() << ", form ; grade required to execute " << rhs.getGradeExec() << ", grade required to sign " << rhs.getGradeSign() << ", is signed " << rhs.getIsSigned());
}

const char	*Form::GradeTooLowException::what() const throw ()
{
	return ("Grade too low exception");
}

const char	*Form::GradeTooHighException::what() const throw ()
{
	return ("Grade too high exception");
}

std::string	Form::getName() const
{
	return (this->name);
}
bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}
int	Form::getGradeExec() const
{
	return (this->gradeExec);
}
void	Form::beSigned(const Bureaucrat b)
{
	if (b.getGrade() <= this->gradeSign)
		this->isSigned = 1;	
	else
		throw (Form::GradeTooLowException());
}
