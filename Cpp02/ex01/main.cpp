/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:50:37 by iren              #+#    #+#             */
/*   Updated: 2022/07/06 18:27:15 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a; // default
	Fixed const b( 10 ); // int
	Fixed const c( 42.42f); // float
	Fixed d(a); // copy

	a = Fixed( 1234.4321f ); // float + copy assignement

	std::cout <<  "a is " << a  << std::endl;
	std::cout <<   "b is " << b << std::endl;
	std::cout <<  "c is " << c   << std::endl;
	std::cout <<  "d is " << d   << std::endl;
	std::cout << "a is " << a.toInt() << " as integer"   << std::endl;
	std::cout << "b is " << b.toInt() << " as integer"   << std::endl;
	std::cout << "c is " << c.toInt() << " as integer"   << std::endl;
	std::cout << "d is " << d.toInt() << " as integer"   << std::endl;
//	std::cout <<    << std::endl;
	return 0;
}
