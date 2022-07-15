/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:32:18 by iren              #+#    #+#             */
/*   Updated: 2022/07/15 01:25:08 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> vect;
	vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

	std::list<int>	l;
	l.push_back(100);
    l.push_back(200);
    l.push_back(333);

	std::vector<int> empty;

	std::cout << easyfind< std::vector<int> >(vect, 1) << std::endl; // looking for 1
    vect.push_back(1);
	std::cout << easyfind< std::vector<int> >(vect, 1) << std::endl; // looking for 1 again

	std::cout << std::endl;
	std::cout << easyfind<std::list<int> >(l, 100) << std::endl; // looking for 100
	std::cout << easyfind<std::list<int> >(l, 10) << std::endl; //looking for 10
	std::cout << easyfind<std::list<int> >(l, 10) << std::endl; //looking for 10

	std::cout << std::endl;
	std::cout << easyfind< std::vector<int> >(empty, 1) << std::endl; // looking for 1
	return (0);
}
