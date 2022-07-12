#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Bureaucrat;
class	Form
{
	private:
		const std::string	name;
		const std::string	target;
		const	int	grade;
		const int execGrade;
		bool	isSigned;

	public:
		virtual ~Form();
		Form(std::string name, int grade, std::string target, int executeGrade);
		Form(const Form &other);
		Form &operator = (const Form &other);

		std::string	getName() const;
		std::string	getTarget() const;
		bool	getIsSigned() const;
		int		getGrade() const;
		int		getExecGrade() const;
		void	beSigned(const Bureaucrat b);
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;

		// Exception classes
		class	GradeTooLowException : public std::exception
	{
		private:
			std::string	_msg;

		public:
			const char	*what() const throw ();
			~GradeTooLowException() throw();
			GradeTooLowException(std::string msg);
	};

		class	GradeTooHighException : public std::exception
	{
		private:
			std::string	_msg;

		public:
			const char	*what() const throw ();
			~GradeTooHighException() throw();
			GradeTooHighException(std::string msg);
	};


};

std::ostream &operator<<(std::ostream &os, const Form &rhs);
#endif
