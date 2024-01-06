#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <climits>
# include <cstdlib> // strtol

# include <stack>
# include <sstream>
# include <string>
# include <cstring> // strcpy

# define ERR_ARG "Error: RPN expression should be in quotation marks."
# define ERR_NOT_A_RPN_EXPR "Error: not a valid RPN expression."
# define ERR_DIV_BY_ZERO "Error: division by zero forbidden."
# define ERR_INT_MAX "Error: INT overflow."
# define ERR_INT_MIN "Error: INT underflow."

# define TOKENS "+-*/"

class RPN
{
	private:
		std::stack<int>	_stack;
		std::string		_tokens;

		bool	is_a_num(std::string& word);
		bool	is_zero(std::string& s);

		/* basic operations */
		static int	multiply(int a, int b);
		static int	add(int a, int b);
		static int	substract(int a, int b);
		static int	divide(int a, int b);


		int	(*get_func(std::string))(int, int);


	public:
		~RPN();
		RPN();
		RPN(const RPN &other);
		RPN &operator = (const RPN &other);

		static bool parse(const char *);
		int			calc(const char*);
		void		print_stack();
};

#endif
