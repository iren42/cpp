#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

//# define DEBUG
class	Fixed
{
	private:
		int					fixedPoint; // fixed-point number value
		static const int	fracBits = 8; // number of fractional bits

	public:
		~Fixed();
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &rhs); // right hand side

		// comparaison operators
		int operator<(const Fixed &rhs) const;
		int operator<=(const Fixed &rhs) const;
		int operator>(const Fixed &rhs) const;
		int operator>=(const Fixed &rhs) const;
		int operator==(const Fixed &rhs) const;
		int operator!=(const Fixed &rhs) const;

		// arithmetic operators
		Fixed	operator+(const Fixed &rhs) const; // fixed1 + fixed2
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		// increment decrement
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(const Fixed &f1, const Fixed &f2);
};

// More arithmetic operators
Fixed	operator+(int value, const Fixed &other); // ivalue + fixed 
Fixed	operator-(int value, const Fixed &other);
Fixed	operator*(int value, const Fixed &other);
Fixed	operator/(int value, const Fixed &other);

Fixed	operator+(const Fixed &other, int ivalue); // fixed + ivalue
Fixed	operator-(const Fixed &other, int ivalue);
Fixed	operator*(const Fixed &other, int ivalue);
Fixed	operator/(const Fixed &other, int ivalue);


std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
#endif
