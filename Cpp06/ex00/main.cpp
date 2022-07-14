/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 04:21:21 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 04:48:39 by iren             ###   ########.fr       */
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
	ss >> ld;
	Literal	l(ld, data);
	std::cout << l << std::endl;
	return (0);
}
