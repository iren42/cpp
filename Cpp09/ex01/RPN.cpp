#include "RPN.hpp"

//		std::cout << << std::endl;
RPN::~RPN()
{
}

RPN::RPN() : _tokens(TOKENS)
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
		_tokens = other._tokens;
	}
	return (*this);
}

/* this function considers that param s should only have TOKENS,
   digits or spaces as characters */
bool	RPN::parse(const char* s)
{
	int		i;
	std::string	t(TOKENS);
	t.append("0123456789 ");
	size_t	pos; 

	i = 0;
	while (s[i])
	{
		pos = t.find(s[i]);
		if (pos == std::string::npos)
			return (false);
		i++;
	}
	return (true);
}

/* we don’t need to manage the brackets or decimal numbers. */
int	RPN::calc(const char *s)
{
	std::stringstream	ss(s);
	std::string			word;
	size_t				pos;
	int					a;
	int					b;
	int	(*func)(int, int) = 0;

	while (ss >> word)
	{
#ifdef DEBUG
		print_stack();
#endif
		/* parse tokens */
		if (word.size() == 1 && is_a_num(word) == false)
		{
			pos = _tokens.find(word);
			/* is it a token? */
			if (pos != std::string::npos)
			{
#ifdef DEBUG
				std::cout << "\ttoken found: " << word << std::endl;
#endif
				if (_stack.size() > 1)
				{
					b = _stack.top();
					_stack.pop();
					a = _stack.top();
					_stack.pop();
#ifdef DEBUG
					std::cout << "\t" << a << "," << b << " = a,b" << std::endl;
#endif
					func = get_func(word);
					if (func)
						_stack.push(func(a, b));
					else
					{
						std::cout << "func pointer was not found" << std::endl;
						throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
					}
#ifdef DEBUG
					std::cout << "\tfunc pointer result = " << _stack.top() << std::endl;
#endif
				}
				else
				{
					throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
				}
			}
			else
			{	
				/* is it a character? */
				if (is_a_num(word) == false)
				{
					std::cout << word << " is NOT a num" << std::endl;
					throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
				}
			}
		}
		else if (word.size() > 1 && is_a_num(word) == false)
		{
			std::cout << word << " is neither a num or a token" << std::endl;
			throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
		}
		else
		{
#ifdef DEBUG
			std::cout << "\t" << word << " is a number!!" << std::endl;
#endif
			_stack.push(ft_atoi(word));
		}
	}
	if (_stack.size() != 1)
			throw std::runtime_error(ERR_NOT_A_RPN_EXPR);	
#ifdef DEBUG
	std::cout << "Result = " << _stack.top() << std::endl;
#endif
	return (_stack.top());
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

bool	RPN::is_a_num(std::string& word)
{
	int	num = atoi(word.c_str());

	if (num == 0 && is_zero(word) == false)
		return (false);
	return (true);
}

int	RPN::ft_atoi(std::string& s)
{
	char	*buf= new char[s.size() + 1];
	strncpy(buf, s.c_str(), s.size() + 1);
	int	n = (atoi(buf));
	delete [] buf;
	return (n);
}

void	RPN::print_stack()
{
	std::stack<int> buf = _stack;

	int	value;
	std::cout << "== PRINT STACK ===" << std::endl;
	while (buf.empty() == false)
	{
		value = buf.top();
		std::cout << value << std::endl;
		buf.pop();
	}
	std::cout << "== END OF PRINT STACK ===" << std::endl;
}

int	RPN::multiply(int a, int b)
{
	long long	c = static_cast<long long>(a) * static_cast<long long>(b);
	if (c > static_cast<long long>(INT_MAX))
		throw std::runtime_error(ERR_INT_MAX);
	if (c < static_cast<long long>(INT_MIN))
		throw std::runtime_error(ERR_INT_MIN);
	return (a * b);
}

int	RPN::add(int a, int b)
{
	long long	c = static_cast<long long>(a) + static_cast<long long>(b);
	if (c > static_cast<long long>(INT_MAX))
		throw std::runtime_error(ERR_INT_MAX);
	if (c < static_cast<long long>(INT_MIN))
		throw std::runtime_error(ERR_INT_MIN);
	return (a + b);
}

int	RPN::substract(int a, int b)
{
	long long	c = static_cast<long long>(a) - static_cast<long long>(b);
	if (c > static_cast<long long>(INT_MAX))
		throw std::runtime_error(ERR_INT_MAX);
	if (c < static_cast<long long>(INT_MIN))
		throw std::runtime_error(ERR_INT_MIN);
	return (a - b);
}

int	RPN::divide(int a, int b)
{
	if (b == 0)
		throw std::runtime_error(ERR_DIV_BY_ZERO);
	long long	c = static_cast<long long>(a) / static_cast<long long>(b);
	if (c > static_cast<long long>(INT_MAX))
		throw std::runtime_error(ERR_INT_MAX);
	if (c < static_cast<long long>(INT_MIN))
		throw std::runtime_error(ERR_INT_MIN);
	return (a / b);
}

int	(*RPN::get_func(std::string op))(int, int)
{
	if (!(op.compare("+")))
		return (&add);
	else if (!(op.compare("-")))
		return (&substract);
	else if (!(op.compare("*")))
		return (&multiply);
	else if (!(op.compare("/")))
		return (&divide);
	else
		return (0);
}
