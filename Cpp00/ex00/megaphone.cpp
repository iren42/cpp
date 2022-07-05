/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:18:10 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/05 21:24:14 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			std::string res(av[i]);
			while (j < (int)res.length())
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
