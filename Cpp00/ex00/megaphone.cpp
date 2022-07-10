/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:18:10 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 14:37:33 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	long unsigned int	i;
	long unsigned int	j;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while ((int)i < ac)
		{
			j = 0;
			std::string res(av[i]);
			while (j < res.length())
			{
				std::cout << (char)toupper(res[j]) << std::flush;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
