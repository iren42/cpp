/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:44:49 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 03:46:07 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

#define N 10
// It randomly instanciates A, B or C and returns the instance as a Base pointer. 
Base	*generate(void)
{
	int	rand = std::rand();

	if (rand % 3 == 0)
		return (new A());
	if (rand % 3 == 1)
		return (new B());
	return (new C());
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "AAAAAA identified" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "BBBBBB identified" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "CCCCCC identified" << std::endl;
	else
		throw (std::exception());
}

int	main()
{
	// init seed for rand()
	srand((unsigned int)time(NULL));
	int	i;

	// generate an array of sub classes (A, B and C) randomly
	Base	*ptr[N];

	i = 0;
	while (i < N)
	{
		ptr[i] = generate();
		i++;
	}
	std::cout << std::endl;

	// find out each sub classes' identity
	i = 0;
	while (i < N)
	{
		identify(ptr[i]);
		delete ptr[i];
		i++;
	}

	// try catch
	std::cout << std::endl;
	try
	{
		Base	p;
		Base	&ref = p;
		identify(&ref);
	}
	catch (std::exception &e)
	{
		std::cout << "neither A or B or B" << std::endl;
	}
	return (0);
}
