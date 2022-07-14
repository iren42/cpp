/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:01:38 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 11:20:09 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "../Awesome.hpp"

int	main()
{
	// TEST FROM GUIDELINES
	int	tab[] = {0, 1, 2, 3, 4};
	Awesome	tab2[5];

	iter(tab, 5, print);
	std::cout << std::endl;
	iter(tab2, 5, print);

	return (0);
}
