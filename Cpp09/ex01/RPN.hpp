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

# define TOKENS "+-*/"

class RPN
{
	private:
		std::stack<int>	_stack;
		static bool	is_a_num(std::string &word);
		static bool	is_zero(std::string &s);


	public:
		~RPN();
		RPN();
		RPN(const RPN &other);
		RPN &operator = (const RPN &other);

		static bool parse(const char *);
		int	calc(const char*);
};

#endif
