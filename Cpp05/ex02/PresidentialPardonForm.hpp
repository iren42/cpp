#ifndef PRESIDENT_PARDON_HPP
# define PRESIDENT_PARDON_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	target;

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &other);

		void	execute(Bureaucrat const &executor);

};

#endif
