/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:50:37 by iren              #+#    #+#             */
/*   Updated: 2022/07/07 11:30:17 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a; // default
	Fixed const b( 1 ); // int
	Fixed const c( -10 ); // int

//	a = Fixed( 1234.4321f ); // float + copy assignement

	std::cout << "a is " << a  << std::endl;
	std::cout << "pre a is " << ++a  << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "post a is " << a++  << std::endl;
	std::cout << "a is " << a  << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "\ta < b is " << (a < b)   << std::endl;
	std::cout << "\ta =< b is " << (a <= b)   << std::endl;
	std::cout << "\ta > b is " << (a > b)   << std::endl;
	std::cout << "\ta >= b is " << (a >= b)   << std::endl;
	std::cout << "\tb >= c is " << (b >= c)   << std::endl;
	std::cout << "\tb <= c is " << (b <= c)   << std::endl;
	std::cout << "\tb == c is " << (b == c)   << std::endl;
	std::cout << "\ta == c is " << (a == c)   << std::endl;
	std::cout << "\tb - c is " << (b - c)   << std::endl;
	std::cout << "\ta - c is " << (a - c)   << std::endl;
	std::cout << "\ta - c is " << (c - a)   << std::endl;
	std::cout << "\tb + c is " << (b + c)   << std::endl;
	Fixed  d( 0 ); // int
	std::cout << "d is " << d << std::endl;
	d = d + 1;
	std::cout << "d = d + 1; d is " << d << std::endl;
	d = b + 1;
	std::cout << "d = b + 1; d is " << d << std::endl;
	d = 1 + b;
	std::cout << "d = 1 + b; d is " << d << std::endl;
	std::cout << "b is " << b << std::endl;
	d = d + 1;
	std::cout << "d = d + 1; d is " << d << std::endl;
	d = 1 + d;
	std::cout << "d = 1 + d; d is " << d << std::endl;
	d = 256 + d - 3 ;
	std::cout << "d = 256 + d - 3; d is " << d << std::endl;
	d - 1;
	std::cout << "d - 1; No change, d is " << d << std::endl;
	d + 1;
	std::cout << "d + 1; No change, d is " << d << std::endl;
	1 + d;
	std::cout << "1 + d; No change, d is " << d << std::endl;
	1 - d;
	std::cout << "1 - d; No change, d is " << d << std::endl;
	d = d - 1;
	std::cout << "d = d - 1; d is " << d << std::endl;

	std::cout << "\tb * d is " << (b * d)   << std::endl;
	std::cout << "\tb * 3 is " << (b * 3)   << std::endl;
	std::cout << "\tb / 0 is " << (b / 0)   << std::endl; // inf
//	std::cout << "division by 0 is " << (5/0)  << std::endl; // Werror=div-by-zero


	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << e   << std::endl;
	std::cout << Fixed::max(a, b)   << std::endl;
	std::cout << Fixed::min(a, b)   << std::endl;
	std::cout << Fixed::max(c, b)   << std::endl;
	std::cout << Fixed::min(c, b)   << std::endl;
//	std::cout <<    << std::endl;
//	std::cout <<    << std::endl;
	return 0;
}
