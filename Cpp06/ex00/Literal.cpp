/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:46 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/13 14:25:20 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

static bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	ft_isprintable(char c)
{
	if (c >= 20 && c <= 127)
		return (1);
	return (0);
}

static int	getAscii(std::string _raw2)
{
	const char	*s = _raw2.c_str();

	if (_raw2.size() == 1)
	{
		if (ft_isprintable(s[0]))
		{
//			std::cout << "in getAscii(): " << ((int)s[0]) << std::endl;
			return ((int)s[0]);
		}
	}
	return (0);
}

static bool	isNan(std::string _raw2)
{
	int	i;
	int	dots;
	bool	isFSyntaxOK;
	int	fs;
	const char	*s = _raw2.c_str();

	if (getAscii(_raw2))
	{
		//	std::cout << "here" << std::endl;
		return (0);
	}
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
	std::cout << "isNan " << isNan(raw2) << ", raw = " << raw << ", raw2 = " << raw2 << std::endl;
	int	ascii = getAscii(_raw2);
	if (ascii >= 20 && ascii <= 127)
	{
		//	os << "'" << (char)ascii << "'" << std::endl;
		setRaw(ascii);
	}
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

void	Literal::setRaw(long double value)
{
	_raw = value;
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
	if (!(_raw >= std::numeric_limits<float>::min() && _raw <= std::numeric_limits<float>::max()) && _raw != 0.0)
		throw Literal::Exception("Exception: limits");
	return (static_cast<float>(_raw));
}

double	Literal::toDouble() const
{
	return (static_cast<double>(_raw));
}

char	Literal::toChar() const
{
	if (_raw < CHAR_MIN || _raw > CHAR_MAX)
		throw Literal::Exception("Exception: limits");
//	std::cout << "re : " << _raw << std::endl;
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

		if (rhs.toChar() >= 20 && rhs.toChar() <= 127)
			os << "'" << rhs.toChar() << "'" << std::endl;
		//	else if (getAscii(rhs.getRawStr()))
		//		os << "'" << rhs.getRawStr() << "'" << std::endl;
		else if (!isNan(rhs.getRawStr()))
			os << "Non displayable" << std::endl;
		else
			os << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		os << "impossible " << e.what() << std::endl;
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
	try
	{
		os << "float: ";
		if (!isNan(rhs.getRawStr()))
		{
			os << rhs.toFloat();
			if (std::fmod(rhs.toDouble(), 1.0) == 0)
				os << ".0";
			os << "f" << std::endl;
		}
		else
		{
			os << "nanf" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		os << "impossible " << e.what() << std::endl;
	}
	// DOUBLE =======
	try
	{
		os << "double: ";
		if (!isNan(rhs.getRawStr()))
		{
			os << rhs.toDouble();
			if (std::fmod(rhs.toDouble(), 1.0) == 0)
				os << ".0";
			//	os << "f" << std::endl;
		}
		else
		{
			os << "nan" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		os << "impossible " << e.what() << std::endl;
	}
	return (os);
}

//		std::cout << << std::endl;
