/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 04:21:21 by iren              #+#    #+#             */
/*   Updated: 2022/07/13 14:00:16 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Missing parameter." << std::endl << "./ex00 <parameter>" << std::endl;
		return (0);
	}
	std::string	data = &av[1][0];
	std::stringstream ss(data);
	long double ld;
	int	e = 'e';
	e++;
	std::cout << e << std::endl;
/*	float	t = 42.f;

	t++;
	std::cout << t << std::endl; // 43.2 */
	ss >> ld;
	Literal	l(ld, data);
/*	std::cout << l.getRaw() << std::endl;
	std::cout << l.getRawStr() << std::endl;
	std::cout <<"Int "<< l.toInt() << std::endl;
	std::cout <<"Float "<< l.toFloat() << std::endl;
	std::cout <<"Double "<< l.toDouble() << std::endl;
	std::cout <<"Char "<< l.toChar() << std::endl;*/
//	std::cout <<"isNan "<< l.isNan(data) << std::endl;

	
/*	float f = 6666666666666666666666666666;
	f++;
	std::cout << f << std::endl; // */
	std::cout << l << std::endl;
//	std::cout <<  << std::endl;
	return (0);
}
