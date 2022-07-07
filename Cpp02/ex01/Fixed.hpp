#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					fixedPoint; // fixed-point number value
		static const int	fracBits = 8; // number of fractional bits

	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &rhs); // right hand side
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
#endif
