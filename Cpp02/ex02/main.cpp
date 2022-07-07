/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:50:37 by iren              #+#    #+#             */
/*   Updated: 2022/07/08 00:44:38 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a; // default
	Fixed const b( 1 ); // int
	Fixed const c( -10 ); // int

//	a = Fixed( 1234.4321f ); // float + copy assignement


	std::cout <<"Testing increment and decrement"    << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "++a is " << ++a  << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "a++ is " << a++  << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "a-- is " << a--  << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "--a is " << --a  << std::endl ;
	std::cout << "a is " << a  << std::endl << std::endl;


	std::cout <<"Testing comparaisons"    << std::endl;
	Fixed	f(-10);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "\ta < b is " << (a < b)   << std::endl;
	std::cout << "\ta <= b is " << (a <= b)   << std::endl;
	std::cout << "\ta > b is " << (a > b)   << std::endl;
	std::cout << "\ta >= b is " << (a >= b)   << std::endl;
	std::cout << "\tb >= c is " << (b >= c)   << std::endl;
	std::cout << "\tb <= c is " << (b <= c)   << std::endl;
	std::cout << "\tb == c is " << (b == c)   << std::endl;
	std::cout << "\tb != c is " << (b != c)   << std::endl;
	std::cout << "\ta == c is " << (a == c)   << std::endl;
	std::cout << "\tc == c is " << (c == c)   << std::endl;
	std::cout << "\tc != c is " << (c != c)   << std::endl;
	std::cout << "\tf == c is " << (f == c)   << std::endl;
	std::cout << "\tf != c is " << (f != c)   << std::endl << std::endl;
	
	std::cout <<"Testing arithmetics"    << std::endl;
	Fixed	g(6);
	Fixed	h(3);
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;

	std::cout << "\tb - c is " << (b - c)   << std::endl;
	std::cout << "\ta - c is " << (a - c)   << std::endl;
	std::cout << "\tc - a is " << (c - a)   << std::endl;
	std::cout << "\tb + c is " << (b + c)   << std::endl;
	std::cout << "\ta + b is " << (a + b)   << std::endl;
	std::cout << "\ta * b is " << (a * b)   << std::endl;
	std::cout << "\tg * h is " << (g * h)   << std::endl;
	std::cout << "\ta / b is " << (a / b)   << std::endl;
	std::cout << "\tg / h is " << (g / h)   << std::endl;
	std::cout << "\tg * g + h / b is " << (g * g + h / b)   << std::endl;
	std::cout << "\ta + b + b - c is " << (a + b + b - c)   << std::endl << std::endl;
	

	std::cout <<"Testing min max"    << std::endl;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed d(50);
	std::cout << e   << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "\tmax(a, d) is " << Fixed::max(a, d)   << std::endl;
	std::cout << "\tmin(a, d) is " << Fixed::min(a, d)   << std::endl;
	std::cout << "\tb const; max(a, b) is " << Fixed::max(a, b)   << std::endl;
	std::cout << "\tb const; min(a, b) is " << Fixed::min(a, b)   << std::endl;
	std::cout << "\tc and b const; max(c, b) is " << Fixed::max(c, b)   << std::endl;
	std::cout << "\tc and b const; min(c, b) is " << Fixed::min(c, b)   << std::endl;
//	std::cout <<    << std::endl;
//	std::cout <<    << std::endl;
	return 0;
}
