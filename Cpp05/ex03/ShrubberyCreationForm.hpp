#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);

		void	execute(Bureaucrat const &executor) const;

};

#endif
