#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
//# define DEBUG
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern
{

	public:
		~Intern();
		Intern();
		Intern(const Intern &other);
		Intern &operator = (const Intern &other);

		Form	*makeForm(const std::string formName, const std::string formTarget);
};

#endif
