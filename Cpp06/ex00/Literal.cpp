/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 09:54:45 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

static bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	isNan(std::string _raw2)
{
	int	i;
	int	dots;
	bool	isFSyntaxOK;
	int	fs;
	const char	*s = _raw2.c_str();

	i = 0;
	dots = 0;
	fs = 0;
	isFSyntaxOK = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
			break ;
		else if (s[i] == '.')
		{
			dots++;
			if (dots > 1)
				break ;
		}
		else if (s[i] == 'f')
		{
			fs++;
			if (isFSyntaxOK)
			{
				if (dots == 0)
				{
					isFSyntaxOK = 0;
					break ;
				}
			}
			if (fs > 1)
				break ;
		}
		i++;
	}
	if (s[i] == '\0' && isFSyntaxOK)
		return (0);
	return (1);
}
//		std::cout << << std::endl;
// Orthodox canonical form
Literal::~Literal()
{
	std::cout << "Literal Destructor called" << std::endl;
}

Literal::Literal(long double raw, std::string raw2) : _raw(raw), _raw2(raw2)
{
	std::cout << "Literal Default constructor called" << std::endl;
	std::cout << "isNan " << isNan(raw2) << std::endl;
}

Literal::Literal(const Literal &other)
{
	std::cout << "Literal Copy constructor called" << std::endl;
	(*this) = other;
}

Literal &Literal::operator=(const Literal &other)
{
	std::cout << "Literal Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		_raw = other._raw;
	}
	return (*this);
}

// ===================================================================================================
// getter setter
long double	Literal::getRaw(void) const
{
	return (_raw);
}

std::string	Literal::getRawStr(void) const
{
	return (_raw2);
}

// ===================================================================================================


int	Literal::toInt() const
{
	return (static_cast<int>(_raw));
}
float	Literal::toFloat() const
{
	return (static_cast<float>(_raw));
}

double	Literal::toDouble() const
{
	return (static_cast<double>(_raw));
}

char	Literal::toChar() const
{
	if (_raw < std::numeric_limits<char>::min() || _raw > std::numeric_limits<char>::max() )
		throw Literal::Exception("Exception: limits");
	return (static_cast<char>(_raw));

}
Literal::Exception::~Exception() throw() {}

Literal::Exception::Exception(std::string msg) : std::exception(), _msg(msg)
{
}

const char	*Literal::Exception::what() const throw ()
{
	const char	*s = &_msg[0];
	return (s);
}
// ===================================================================================================
std::ostream &operator<<(std::ostream &os, const Literal &rhs)
{
	// CHAR ======
	try
	{
		os << "char: ";
		if (rhs.toChar() >= 32 && rhs.toChar() <= 127)
			os << "'" << rhs.toChar() << "'" << std::endl;
		else if (!isNan(rhs.getRawStr()))
			os << "Non displayable" << std::endl;
		else
			os << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		os << "impossible" << std::endl;
	}
	// INT ======
	os << "int: ";
	if (!isNan(rhs.getRawStr()))
	{
		os << rhs.toInt() << std::endl;
	}
	else
		os << "impossible" << std::endl;
	// FLOAT =======
	os << "float: ";
	if (!isNan(rhs.getRawStr()))
	{
		os << rhs.toFloat();
		if (rhs.toFloat() / 1 == rhs.toFloat())
			os << ".0";
		os << "f" << std::endl;
	}

	os << "double: " << rhs.toDouble() << std::endl;
	return (os);
}

//		std::cout << << std::endl;
