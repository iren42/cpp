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

void	PmergeMe::print_list(std::list<int>& myList)
{
	std::cout << "l = { ";
	for (int n : myList)
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
	// group the elements into n/2 pairs and sort each pair
	int	size = _l.size();
	int	i = 0;
	std::list<int>::iterator iti = _l.begin();
	std::list<int>::iterator itp = _l.begin();

	itp++;
	std::list<std::pair<int,int>> bigList;
	while (i < size / 2)
	{
		if (*iti < *itp)
		bigList.push_back(std::make_pair(*iti, *itp));
		else
		bigList.push_back(std::make_pair(*itp, *iti));
		// increment to the next pair
		i++;
		iti++;
		iti++;
		itp++;
		itp++;
	}
	// last element in a odd number of elements
	if (size % 2)
		int	last = *iti;
	// recursively sort the n/2 larger elements from each pair
	list_recursive_sort(bigList);
}

void	PmergeMe::list_recursive_sort(std::list<std::pair<int, int>>& l)
{
	if (larger_ele_are_sorted(l) == true)
	return ;
	
}

bool	PmergeMe::larger_ele_are_sorted(std::list<std::pair<int, int>>& l)
{
	std::list<std::pair<int, int>>::iterator	iti = l.begin();
	std::list<std::pair<int, int>>::iterator	itp = l.begin();

	itp++;
	while (iti != l.end() && itp != l.end())
	{
		std::cout << (*iti).second << " " << (*itp).second << std::endl;
		if ((*iti).second > (*itp).second)
		{
			std::cout << "Larger ele are not sorted" << std::endl;
			return (false);
		}
		iti++;
		iti++;
		itp++;
		itp++;
	}
	return (true);
}

void	PmergeMe::sort()
{
	print_list(_l);
	sort_list();
	/* sort_vector(); */
	print_list(_l);

}
