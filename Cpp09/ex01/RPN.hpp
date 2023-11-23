#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <cstring> // strchr
# include <exception>
# include <stdlib.h> // atoi

# define ERR_ARG "Error: does not have the right number of arguments."
# define ERR_NOT_A_RPN_EXPR "Error: not a RPN expression."
# define ERR_DIV_BY_ZERO "Error: division by zero forbidden."

# define TOKENS "+-*/"

/* basic operations */
int	multiply(int a, int b);
int	add(int a, int b);
int	substract(int a, int b);
int	divide(int a, int b);

int	(*get_func(std::string))(int, int);
int	ft_atoi(std::string);

class RPN
{
	private:
		std::stack<int>	_stack;
		char*	_tokens;
		int		_res;
		static bool	is_a_num(std::string &word);
		static bool	is_zero(std::string &s);
		void	init_op();


	public:
		~RPN();
		RPN();
		RPN(const RPN &other);
		RPN &operator = (const RPN &other);

		static bool parse(const char *);
		int	calc(const char*);
		void	print_stack();
};

#endif
