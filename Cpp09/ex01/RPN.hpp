#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <cstring> // strchr
# include <exception>
# include <stdlib.h> // atoi
//# define DEBUG

# define ERR_ARG "Error: does not have the right number of arguments."
# define ERR_NOT_A_RPN_EXPR "Error: not a RPN expression."

# define TOKENS "+-*/"

bool	parse(const char *s);
bool	is_a_num(std::string &word);
bool	is_zero(std::string &s);

class RPN
{
	protected:

	public:
		~RPN();
		RPN();
		RPN(const RPN &other);
		RPN &operator = (const RPN &other);

		int	calc(const char*);
};

#endif
