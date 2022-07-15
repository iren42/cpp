#include "Span.hpp"

# define RT   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GR   "\033[32m"      /* Green */
# define YEL  "\033[33m"      /* Yellow */
# define BL    "\033[34m"      /* Blue */

int	main()
{
	srand((unsigned int)time(NULL));
	// TEST 1 : test from the subject
	std::cout << RED << " TEST 1: subject ********************" << RT <<  std::endl;
	try
	{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.display();
	std::cout << BL << sp.shortestSpan() << RT << std::endl;
	std::cout << GR << sp.longestSpan() << RT << std::endl;
}
catch(std::exception &e)
{
	std::cout << RED << "Caught: " << e.what() << RT << std::endl;
}
	// TEST 2 : 1000 numbers
	std::cout << RED <<  " TEST 2: 10000 ********************" << RT << std::endl;
	{
	Span s = Span(10000);
	s.setVec(range_add_with_rand(10000));
	s.display();
	std::cout << BL << s.shortestSpan() << RT << std::endl;
	std::cout << GR << s.longestSpan() <<  RT << std::endl;
	}

	// TEST 3: copy
	std::cout << RED << " TEST 3: copy ********************" << RT << std::endl;
	{
		Span s = Span(10);
		s.setVec(range_add_with_rand(10));
		s.display();
		{
			Span	copy(s);
			copy.display();
			copy.setVec(range_add_with_rand(10));
			copy.display();
		}
		s.display();
	}
	// TEST 4: exception, vector too small (0 or 1 number of int)
	std::cout << RED << " TEST 4: exception ********************" << RT << std::endl;
	try
	{
		Span s = Span(1);

	std::cout << BL << s.shortestSpan() << RT << std::endl;
	std::cout << GR << s.longestSpan() <<  RT << std::endl;

	}
	catch(std::exception &e)
	{
	std::cout << RED << "Caught: " << e.what() << RT << std::endl;
	}
// TEST 5: exception, vector too small (0 or 1 number of int)
	std::cout << RED << " TEST 5: exception ********************" << RT << std::endl;
	try
	{
		Span s = Span(0);

	std::cout << BL << s.shortestSpan() << RT << std::endl;
	std::cout << GR << s.longestSpan() <<  RT << std::endl;

	}
	catch(std::exception &e)
{
	std::cout << RED << "Caught: " << e.what() << RT << std::endl;
}
// TEST 6: exception, add number when Span is already full
	std::cout << RED << " TEST 6: exception ********************" << RT << std::endl;
	try
	{
		Span s = Span(3);

		s.addNumber(5);
		s.display();
		s.addNumber(1);
		s.display();
		s.addNumber(9);
		s.display();
		s.addNumber(3);
		s.display();
	}
	catch(std::exception &e)
{
	std::cout << RED << "Caught: " << e.what() << RT << std::endl;
}


}
