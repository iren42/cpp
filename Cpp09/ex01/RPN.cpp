#include "RPN.hpp"

//		std::cout << << std::endl;
RPN::~RPN()
{
}

RPN::RPN()
{

}


RPN::RPN(const RPN &other)
{
	(*this) = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

/* this function considers that param s should only have TOKENS,
   digits or spaces as characters */
bool	RPN::parse(const char* s)
{
	int		i;
	char	*p = 0;
	std::string	t(TOKENS);
	t.append("0123456789 ");
	char	*auth_char= new char[t.size() + 1];

	strcpy(auth_char, t.c_str());
	i = 0;
	while (s[i])
	{
		p = strchr(auth_char, s[i]);
		if (p == 0)
			return (false);
		i++;
	}
	return (true);
}

int	RPN::calc(const char *s)
{
	std::stringstream	ss(s);
	std::string	word;
	char	*p = 0;

	/* necessary to use strchr() */
	std::string	t(TOKENS);
	char	*tokens = new char[t.size() + 1];
	strcpy(tokens, t.c_str());

	while (ss >> word)
	{
		/* parse tokens */
		if (word.size() == 1 && is_a_num(word) == false)
		{
			p = strchr(tokens, word[0]);
			/* is it a token? */
			if (p != 0)
				std::cout << "token found: " << word[0] << std::endl;
			else
			{	
				/* is it a character? */
				if (is_a_num(word) == false)
				{
					std::cout << word << " is NOT a num" << std::endl;
					delete tokens;
					throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
				}
			}
		}
		else if (word.size() > 1 && is_a_num(word) == false)
		{
			std::cout << word << " is neither a num or a token" << std::endl;
			delete tokens;
			throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
		}
		else
			std::cout << word << " is a number!!" << std::endl;
	}
	delete tokens;
	return (0);
}

bool	RPN::is_zero(std::string &s)
{
	std::string::iterator	it = s.begin();

	if (s.at(0) == '-' && s.size() > 1)
		it++;
	while (it != s.end())
	{
		if ((*it) != '0')
			return (false);
		it++;
	}
	return (true);
}

bool	RPN::is_a_num(std::string &word)
{
	int	num = atoi(word.c_str());

	/* std::cout << num << " num, is_zero: " << is_zero(word) << std::endl; */
	if (num == 0 && is_zero(word) == false)
		return (false);
	return (true);
}
