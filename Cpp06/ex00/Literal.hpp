#ifndef LITERAL_HPP
# define LITERAL_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <limits>
#include <cmath>
#define FLT_MIN 1.175494351e-38F
#define FLT_MAX 3.402823466e+38F

class Literal
{
	private:
		long double	_raw;
		std::string	_raw2;

	public:
		~Literal();
		Literal(long double raw, std::string raw2);
		Literal(const Literal &other);
		Literal &operator = (const Literal &other);

		long double	getRaw(void) const;
		std::string	getRawStr(void) const;
		void	setRaw(long double value);
		int	toInt() const;
		float	toFloat() const;
		double	toDouble() const;
		char	toChar() const;


	class	Exception : public std::exception
	{
		private:
			std::string	_msg;

		public:
			const char	*what() const throw ();
			~Exception() throw();
			Exception(std::string msg);
	};


};

std::ostream &operator<<(std::ostream &os, const Literal &rhs);
#endif
