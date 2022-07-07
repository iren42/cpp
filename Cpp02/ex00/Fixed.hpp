#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed
{
	private:
		int					fp_nb_value;
		static const int	nb_frac_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &rhs);
	//	Fixed &operator = (const Fixed &rhs);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

};
#endif
