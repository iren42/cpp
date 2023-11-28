#include "PmergeMe.hpp"

int	main(int ac, char *av[])
{
	try
	{
		if (ac < 2)
		{
			throw std::runtime_error(ERR_ARG);
		}
		else
		{
			if (PmergeMe::parse(ac, av) == false)
				throw std::runtime_error(ERR_INPUT);
			PmergeMe pmerge(ac, av);
			pmerge.print_list();
			pmerge.print_vector();
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
