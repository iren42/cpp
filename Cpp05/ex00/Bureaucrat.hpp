#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
//# define DEBUG

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;

	public:
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator = (const Bureaucrat &other);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void	upGrade();
		void	downGrade();


		// Exception classes
		class	GradeTooLowException : public std::exception
	{
		const char	*what() const throw ();
	};


		class	GradeTooHighException : public std::exception
	{
		const char	*what() const throw ();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);
#endif
