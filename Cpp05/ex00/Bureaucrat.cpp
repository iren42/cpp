/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 19:01:07 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy assignment constructor called" << std::endl;
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

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade = grade;
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
