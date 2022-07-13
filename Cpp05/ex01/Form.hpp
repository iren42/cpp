#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
//# define DEBUG

class	Bureaucrat;
class	Form
{
	private:
		const std::string	name;
		const	int	gradeSign;
		const	int	gradeExec;
		bool	isSigned;

	public:
		~Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &other);
		Form &operator = (const Form &other);

		std::string	getName() const;
		bool	getIsSigned() const;
		int	getGradeSign() const;
		int	getGradeExec() const;
		void	beSigned(const Bureaucrat b);

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

std::ostream &operator<<(std::ostream &os, const Form &rhs);
#endif
