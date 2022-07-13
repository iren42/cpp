#ifndef LITERAL_HPP
# define LITERAL_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <math>

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
