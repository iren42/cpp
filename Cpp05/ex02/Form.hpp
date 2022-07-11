#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Bureaucrat;
class	Form
{
	private:
		const std::string	name;
		const	int	grade;
		bool	isSigned;

	public:
		virtual ~Form();
		Form(std::string name, int grade);
		Form(const Form &other);
		Form &operator = (const Form &other);

		std::string	getName() const;
		bool	getIsSigned() const;
		int	getGrade() const;
		void	beSigned(const Bureaucrat b);
		virtual void	execute(Bureaucrat const &executor) = 0;

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
