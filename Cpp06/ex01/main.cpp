/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:16:35 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 02:39:57 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main()
{
	Data *d = new Data(40);
	uintptr_t	tmp = serialize(d);
	Data *newD = deserialize(tmp);

	std::cout << d << std::endl;
	std::cout << tmp << std::endl;
	std::cout << newD << std::endl;

	delete d;
//	std::cout << << std::endl;
}
