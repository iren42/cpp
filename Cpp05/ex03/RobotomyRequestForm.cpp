/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 07:59:21 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//		std::cout << << std::endl;
RobotomyRequestForm::~RobotomyRequestForm()
{
#ifdef DEBUG
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, target, 45)
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
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
	Form::execute(executor);
		srand((unsigned int)time(NULL));
		if (std::rand() % 2)
			std::cout << "Drrr... " << this->getTarget() << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}
