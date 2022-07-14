/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:44:49 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 03:21:24 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

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
	if (dynamic_cast<A*>(p))
		std::cout << "AAAAAA identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "BBBBBB identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "CCCCCC identified" << std::endl;
}

int	main()
{
	// init seed for rand()
	srand((unsigned int)time(NULL));

	// generate a sub class randomly
	Base	*ptr = generate();

	// find out which sub class was generated
	identify(ptr);
	delete ptr;
}
