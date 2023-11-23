#include "RPN.hpp"

//		std::cout << << std::endl;
RPN::~RPN()
{
	print_stack();
	delete _tokens;
}

RPN::RPN() : _res(0)
{
	/* init _tokens */
	std::string	buf(TOKENS);
	_tokens = new char[buf.size() + 1];
	memset(_tokens, 0, buf.size() + 1);
	strncpy(_tokens, buf.c_str(), buf.size());
	/* init operation functions */
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
		delete _tokens;
		int i = sizeof(other._tokens) / sizeof(other._tokens[0]);
		std::cout << i << std::endl;
		_tokens = new char[i + 1];
		strncpy(_tokens, other._tokens, i + 1);

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
		p = strchr(auth_char, s[i]); // strchr do not work with a const char array
		if (p == 0)
		{
			delete auth_char;
			return (false);
		}
		i++;
	}
	delete auth_char;
	return (true);
}

int	RPN::calc(const char *s)
{
	std::stringstream	ss(s);
	std::string	word;
	char	*p = 0;
	int	a;
	int	b;
	int	(*func)(int, int) = 0;

	/* necessary to use strchr() */

	while (ss >> word)
	{
		/* parse tokens */
		if (word.size() == 1 && is_a_num(word) == false)
		{
			p = strchr(_tokens, word[0]);
			/* is it a token? */
			if (p != 0)
			{
				std::cout << "token found: " << word[0] << std::endl;
				if (_stack.size() >= 2)
				{
					b = _stack.top();
					_stack.pop();
					a = _stack.top();
					_stack.pop();
					std::cout << a << "," << b << " = a,b" << std::endl;
					func = get_func(word);
					if (func)
						_res = func(a, b);
					else
						std::cout << "func pointer was not found " << std::endl;

					std::cout << "func pointer: " << _res << std::endl;
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
			std::cout << word << " is a number!!" << std::endl;
			_stack.push(ft_atoi(word));
		}
	}
	std::cout << " res = " << _res << std::endl;
	return (_res);
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

int	ft_atoi(std::string s)
{
	char	*buf= new char[s.size() + 1];
	strcpy(buf, s.c_str());
	int	n = (atoi(buf));
	delete buf;
	return (n);
}

void	RPN::print_stack()
{
	std::stack<int> buf = _stack;

	int	value;
	std::cout << "=====" << std::endl;
	while (buf.empty() == false)
	{
		value = buf.top();
		std::cout << value << std::endl;
		buf.pop();
	}
}



int	multiply(int a, int b)
{
	return (a * b);
}
int	add(int a, int b)
{
	return (a + b);
}
int	substract(int a, int b)
{
	return (a - b);
}
int	divide(int a, int b)
{
	if (b == 0)
	{
		throw std::runtime_error(ERR_DIV_BY_ZERO);
	}
	return (a / b);
}

int	(*get_func(std::string op))(int, int)
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
