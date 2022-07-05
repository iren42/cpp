/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:22:35 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/04 13:10:44 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	hi;
	std::string	*stringPTR;
	std::string	&stringREF = hi;

	hi = "HI THIS IS BRAIN";
	stringPTR = &hi;

	// Memory addresses
	std::cout << &hi << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	// Values
	std::cout << hi << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
