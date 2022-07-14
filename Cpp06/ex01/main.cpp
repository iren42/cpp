/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:16:35 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 05:57:18 by iren             ###   ########.fr       */
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

	std::cout << "uintptr_t value = " << tmp << std::endl;
	std::cout << "initial Data* : " << d << std::endl;
	std::cout << "new Data* : " << newD << std::endl;
	std::cout << "new Data* calls its member function : " << std::flush;
	newD->sing();
	std::cout << std::endl;
	std::cout << "old Data* calls its member function too : " << std::flush;
	d->sing();
	std::cout << "Final data struct is indeed usable" << std::endl;

	delete d;
//	std::cout << << std::endl;
}
