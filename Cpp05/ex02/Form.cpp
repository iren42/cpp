/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:05:57 by isabelle         ###   ########.fr       */
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

Form::Form(std::string name, int grade) : name(name), grade(grade), isSigned(0)
{
#ifdef DEBUG
	std::cout << "Form Default constructor called" << std::endl;
#endif
	if (grade > 150)
		throw (Form::GradeTooLowException("Exception: grade is too low to instantiate"));
	else if (grade < 1)
		throw (Form::GradeTooHighException("Exception: grade is too high to instantiate"));
}

Form::Form(const Form &other) : name(other.name), grade(other.grade), isSigned(other.isSigned)
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
	return (os << rhs.getName() << ", form grade " << rhs.getGrade() << ", is signed " << rhs.getIsSigned());
}

// Exception classes

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(std::string msg) : std::exception(), _msg(msg)
{
}

const char	*Form::GradeTooLowException::what() const throw ()
{
	const char	*s = &_msg[0];
	return (s);
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(std::string msg) : std::exception(), _msg(msg)
{
}

const char	*Form::GradeTooHighException::what() const throw ()
{
	const char	*s = &_msg[0];
	return (s);
}

// Member functions
std::string	Form::getName() const
{
	return (this->name);
}
bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGrade() const
{
	return (this->grade);
}

void	Form::beSigned(const Bureaucrat b)
{
	if (b.getGrade() <= this->grade)
		this->isSigned = 1;	
	else
		throw (Form::GradeTooLowException("Exception: grade too low to sign"));
}
