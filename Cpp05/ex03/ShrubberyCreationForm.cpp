/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/12 07:15:45 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
//		std::cout << << std::endl;

ShrubberyCreationForm::~ShrubberyCreationForm()
{
#ifdef DEBUG
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, target, 137)
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
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		Form::execute(executor);
		std::string		filename = getTarget();
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
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}
