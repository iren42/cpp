/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:22:25 by iren              #+#    #+#             */
/*   Updated: 2022/07/14 19:29:53 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <cstdlib>
#include "Array.hpp"
#include "../Awesome.hpp"
# define RT   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GR   "\033[32m"      /* Green */
# define YEL  "\033[33m"      /* Yellow */
# define BL    "\033[34m"      /* Blue */
int	main()
{
	srand((unsigned int)time(NULL));
	{
		int	i= 0;
		Array<int> intBigArray(15);
		while (i < 15)
		{
			intBigArray[i] = std::rand();
			i++;
		}
		std::cout << YEL << intBigArray << RT << std::endl;
		Array<int> intArray(5);
		std::cout << YEL << intArray << RT << std::endl; // every value is initialized by default 
		intArray[0] = 10;								// for int , it's 0
		intArray[1] = 100;
		intArray[2] = 4;
		intArray[3] = 78;
		intArray[4] = 13;
		std::cout << YEL << intArray << RT << std::endl;
		std::cout << "values set for intArray" << std::endl;
		// TEST 1 : deep copy with copy constructor and copy assign constructor
		{
			Array<int> intArrCopy(intArray);
			std::cout << YEL << intArrCopy << RT << std::endl;
			Array<int> intArrAssign = intArray;
			std::cout << YEL << intArrAssign << RT << std::endl;
			intArrCopy[0] = 33;
			intArrCopy[1] = 33;
			intArrCopy[2] = 33;
			std::cout << YEL << intArrCopy << RT << std::endl;
		}
		std::cout  << std::endl;
		std::cout << YEL << intArray << RT << std::endl; // intArray's values are not changed
		// TEST 1 bis : copy assign from a much bigger array
		intArray = intBigArray;
		std::cout << YEL << intBigArray << RT << std::endl;
		std::cout << YEL << intArray << RT << std::endl; 

	}

	std::cout  << std::endl;
	std::cout  << std::endl;
	// TEST 2 : test with std::string
	{	Array<std::string> strArray(3);
		std::cout << GR << strArray << RT << std::endl;
		strArray[0] = "hi "; // set values
		strArray[1] = "my name is";
		strArray[2] = " PARIS";
		std::cout << GR << strArray << RT << std::endl; // */


		Array<std::string> strArrayBis = strArray;
		std::cout << GR << strArrayBis << RT << std::endl;
		strArrayBis[2] = "NEW YORK";
		std::cout  << std::endl;
		std::cout << GR << strArray << RT << std::endl; // */
		std::cout << GR << strArrayBis << RT << std::endl;
		//	std::cout << << std::endl;
		//	std::cout << << std::endl;

	}
	// TEST 3: access an element out of bounds
	try
	{
		Array<float> fEmpty;
		std::cout << BL << fEmpty << RT << std::endl;
		Array<float> fArray(4);
		fArray[0] = 1.0f;
		std::cout << BL << fArray << RT << std::endl;
		fArray[4] = 3.5;
		std::cout << BL << fArray << RT << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << RED << "Caught: " << e.what() << RT << std::endl;

	}
	return (0);
}
