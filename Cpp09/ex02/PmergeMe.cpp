#include "PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
	/* print_stack(); */
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		/* std::cout << av[i] << std::endl; */
		_l.push_back(atoi(av[i]));
		_v.push_back(atoi(av[i]));
		i++;
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(*this) = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_l = other._l;
		_v = other._v;
	}
	return (*this);
}

/* instructions:
   Your program must be able to use a positive integer sequence as argument. */
bool	PmergeMe::parse(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		/* std::cout << av[i] << std::endl; */
		std::string buf(av[i]);
		if (is_a_posi_num(buf) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	PmergeMe::is_zero(std::string &s)
{
	std::string::iterator	it = s.begin();

	while (it != s.end())
	{
		if ((*it) != '0')
			return (false);
		it++;
	}
	return (true);
}

bool	PmergeMe::is_a_posi_num(std::string& word)
{
	int	num = atoi(word.c_str());

	if (num == 0 && is_zero(word) == false)
		return (false);
	return (true && num >= 0);
}

void	PmergeMe::print_list()
{
	std::cout << "l = { ";
	for (int n : _l)
		std::cout << n << ", ";
	std::cout << "};\n";
}

void	PmergeMe::print_vector()
{
	std::cout << "v = { ";
	for (int n : _v)
		std::cout << n << ", ";
	std::cout << "};\n";
}

void	PmergeMe::sort_list()
{


}
