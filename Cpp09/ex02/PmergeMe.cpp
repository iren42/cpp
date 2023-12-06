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

void	PmergeMe::print_list_of_pairs(LIST& l)
{
	LIST::iterator	it = l.begin();
	std::cout << "list of pairs = { ";
	while (it != l.end())
	{
		std::cout << "(" << (*it).first << "," << (*it).second << "), " << std::flush;
		it++;
	}
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
	print_list_of_pairs(bigList);
	// last element in a odd number of elements
	if (size % 2)
		int	last = *iti;
	// recursively sort the n/2 larger elements from each pair
	std::cout << "bigList size= " << bigList.size() << std::endl;
	merge_sort(bigList, 0, bigList.size() - 1);
}
// Merges two sublists of list.
// First sublist is arr[begin..mid]
// Second sublist is arr[mid+1..end]
void PmergeMe::merge(std::list<std::pair<int,int>>& list, int const left, int const mid,
		int const right)
{
	int const subListOne = mid - left + 1;
	int const subListTwo = right - mid;
	std::cout << "left="<<left << " , mid=" << mid << " , right= " << right << std::endl;

	// Create temp lists
	LIST	leftList;
	LIST	rightList;

	// Copy data to temp lists leftlist[] and rightlist[]
	int	i = 0;
	int	j = 0;
	LIST::iterator	it = list.begin();
	while (i < left)
	{
		it++;
		i++;
	}
	i = 0;
	while (i < subListOne)
	{
		leftList.push_back(*it);
		it++;
		i++;
	}
	it = list.begin();
	while (j < mid + 1)
	{
		it++;
		j++;
	}
	j = 0;
	while (j < subListTwo)
	{
		rightList.push_back(*it);
		it++;
		j++;
	}
	std::cout << "Left list: " << std::flush;
	print_list_of_pairs(leftList);
	std::cout << "\nRight list: " << std::flush;
	print_list_of_pairs(rightList);


	LIST::iterator	itsl1 = leftList.begin();
	LIST::iterator	itsl2 = rightList.begin();
	LIST::iterator	itMergedList = list.begin();
	int indexOfSublistOne = 0, indexOfSublistTwo = 0;
	i = 0;
			std::cout << "left= "<< i << "<" << left << std::endl;
	while (i < left)
	{
		i++;
		itMergedList++;	
	}
		std::cout << "debug0 " << std::distance(list.begin(), itMergedList) <<  std::endl;
	/* int indexOfMergedlist = left; */

	// Merge the temp lists back into list[left..right]
	while (indexOfSublistOne < subListOne
			&& indexOfSublistTwo < subListTwo)
	{
		std::cout << "LOOPED" << std::endl;
		std::cout << indexOfSublistOne << "<" << subListOne << " et "<< indexOfSublistTwo << "<" << subListTwo<< std::endl;
		/* if (leftList[indexOfSublistOne] */
		/* 		<= rightList[indexOfSublistTwo]) */
		if ((*itsl1).second <= (*itsl2).second)
		{
			std::cout << (*itsl1).second << " <= " << (*itsl2).second << std::endl;
		itMergedList = list.erase(itMergedList);
			list.insert(itMergedList, *(itsl1));
			itsl1++;
			/* list[indexOfMergedlist] */
			/* 	= leftlist[indexOfSublistOne]; */
			indexOfSublistOne++;
			std::cout << indexOfSublistOne << std::endl;
		}
		else
		{
		itMergedList = list.erase(itMergedList);
			list.insert(itMergedList, *(itsl2));
			itsl2++;
			/* list[indexOfMergedlist] */
			/* 	= rightlist[indexOfSublistTwo]; */
			indexOfSublistTwo++;
		}
		/* indexOfMergedlist++; */
		/* itMergedList++; */
	}
		std::cout << "debug1 " << std::distance(list.begin(), itMergedList) <<  std::endl;
	print_list_of_pairs(list);

	/* // Copy the remaining elements of */
	/* // left[], if there are any */
	/* while (indexOfSublistOne < sublistOne) { */
	/* 	list[indexOfMergedlist] */
	/* 		= leftlist[indexOfSublistOne]; */
	/* 	indexOfSublistOne++; */
	/* 	indexOfMergedlist++; */
	/* } */
	while (itsl1 != leftList.end())
	{
		itMergedList = list.erase(itMergedList);
		list.insert(itMergedList, *(itsl1));
		/* list.push_back(*(itsl1)); */
		itsl1++;
		/* itMergedList++; */
	}
	print_list_of_pairs(list);

	/* // Copy the remaining elements of */
	/* // right[], if there are any */
	/* while (indexOfSublistTwo < sublistTwo) { */
	/* 	list[indexOfMergedlist] */
	/* 		= rightlist[indexOfSublistTwo]; */
	/* 	indexOfSublistTwo++; */
	/* 	indexOfMergedlist++; */
	/* } */
	while (itsl2 != rightList.end())
	{
	
		std::cout << "debug2 " << std::distance(list.begin(), itMergedList) <<  std::endl;
		itMergedList = list.erase(itMergedList);
		list.insert(itMergedList, *(itsl2));
		/* list.push_back(*(itsl2)); */
		itsl2++;
		/* itMergedList++; */
	}
	std::cout << "After merge_sort list: " << std::flush;
	print_list_of_pairs(list);
	/* delete[] leftList; */
	/* delete[] rightList; */
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void PmergeMe::merge_sort(std::list<std::pair<int,int>> &list, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	std::cout << "mid=" << mid << std::endl;
	merge_sort(list, begin, mid);
	merge_sort(list, mid + 1, end);
	merge(list, begin, mid, end);
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
