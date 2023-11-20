#include "RPN.hpp"

//		std::cout << << std::endl;
RPN::~RPN()
{
	std::cout << "RPN Destructor called" << std::endl;
}

RPN::RPN()
{
	std::cout << "RPN Default constructor called" << std::endl;

}


RPN::RPN(const RPN &other)
{
	std::cout << "RPN Copy constructor called" << std::endl;
	(*this) = other;
}

RPN &RPN::operator=(const RPN &other)
{
	std::cout << "RPN Copy assignment constructor called" << std::endl;
	return (*this);
}

int	RPN::calc(const char* s)
{
	return (0);
}

bool	RPN::parse(const char *s)
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
			std::cout << word << std::endl;
	}
	delete tokens;
	return (true);
}

bool	RPN::is_zero(std::string &s)
{
	std::string::iterator	it = s.begin();

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

	std::cout << num << " num, strcmp: " << strcmp(word.c_str(), "0") << std::endl;
	if (num == 0 && is_zero(word) == false)
		return (false);
	return (true);
}

