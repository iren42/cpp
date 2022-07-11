/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:57:08 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//		std::cout << << std::endl;
Bureaucrat::~Bureaucrat()
{
#ifdef DEBUG
	std::cout << "Bureaucrat Destructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
#ifdef DEBUG
	std::cout << "Bureaucrat Default constructor called" << std::endl;
#endif
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
#ifdef DEBUG
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
#endif
	if (this != &other)
	{
		this->grade = other.grade;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
#ifdef DEBUG
	std::cout << "Bureaucrat Copy assignment constructor called" << std::endl;
#endif
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
}

const char	*Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Grade too low exception");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Grade too high exception");
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::downGrade()
{
	this->grade++;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::upGrade()
{
	this->grade--;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());

}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}



void	Bureaucrat::executeForm(Form const &form)
{
	
}
