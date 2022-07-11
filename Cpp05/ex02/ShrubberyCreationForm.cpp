/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 23:47:41 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
//		std::cout << << std::endl;

#define GRADE_EXEC_SC 137

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145), target(target)
{
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
#endif

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other)
{
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
#endif
	(*this) = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm Copy assignment constructor called" << std::endl;
#endif
	if (this != &other)
	{
		Form::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() && executor.getGrade() <= GRADE_EXEC_SC)
	{
		std::string		filename = this->target;
		filename.append("_shrubbery");

		std::cout << filename << std::endl;
		std::ofstream	ofs(filename.c_str(), std::ofstream::out);

		ofs <<"       ###" << std::endl;
		ofs <<"      #o###" << std::endl;
		ofs <<"    #####o###" << std::endl;
		ofs <<"   #o#\\#|#/###" << std::endl;
		ofs <<"    ###\\|/#o#" << std::endl;
		ofs <<"     # }|{  #" << std::endl;
		ofs <<"ejm97  }|" << std::endl << std::endl;


		ofs <<"                  %%%,%%%%%%%" << std::endl;
		ofs <<"                   ,'%% \\-*%%%%%%%" << std::endl;
		ofs <<"             ;%%%%%*%   _%%%%" << std::endl;
		ofs <<"              ,%%%       \(_.*%%%%." << std::endl;
		ofs <<"              % *%%, ,%%%%*(    '" << std::endl;
		ofs <<"            %^     ,*%%% )\\|,%%*%,_" << std::endl;
		ofs <<"                 *%    \\/ #).-'*%%*" << std::endl;
		ofs <<"                     _.) ,/ *%," << std::endl;
		ofs <<"             _________/)#(_____________" << std::endl;
		ofs <<"            b'ger" << std::endl;

		ofs.close();
	}
	else if (!this->getIsSigned())
		throw (Form::GradeTooLowException("Exception: form is not signed"));
	else
		throw (Form::GradeTooLowException("Exception: grade is too low to execute"));
}
