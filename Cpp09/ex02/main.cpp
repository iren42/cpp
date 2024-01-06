#include "PmergeMe.hpp"

int	main(int ac, char *av[])
{
	try
	{
		if (ac < 3)
			throw std::runtime_error(ERR_ARG);
		if (PmergeMe::parse(ac, av) == false)
			throw std::runtime_error(ERR_INPUT);
		PmergeMe pmerge(ac, av);
		pmerge.sort();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

/* ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "` */
