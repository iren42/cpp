#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	target;

	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &other);

		void	execute(Bureaucrat const &executor);

};

#endif
