#include "PmergeMe.hpp"

// ------- NON MEMBER FUNCTIONS
void	print_list(std::list<int>& myList)
{
	std::list<int>::iterator	it = myList.begin();
	while (it != myList.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	print_list_of_pairs(LIST& l)
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

void	print_vec(std::vector<int>& v)
{
	std::vector<int>::iterator	it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	print_vec_of_pairs(VECTOR& l)
{
	VECTOR::iterator	it = l.begin();
	std::cout << "vector of pairs = { ";
	while (it != l.end())
	{
		std::cout << "(" << (*it).first << "," << (*it).second << "), " << std::flush;
		it++;
	}
	std::cout << "};\n";
}

// calculate the size of groups of to-be-inserted-elements
// sums of sizes of every two adjacent groups form a sequence of powers of two
int	calc_size_group(int i, int buf)
{
	return ((1 << i) - buf);
}

// calculate how many microseconds have passed from start to end
long int calc_usec(struct timeval& start, struct timeval& end)
{
	long int	usec;

	usec = (end.tv_sec - start.tv_sec) * 1000000; // convert sec to usec
	if (end.tv_usec - start.tv_usec < 0)
	{
		/* std::cout << "full round of usec" << std::endl; */
		usec += 1000000;
	}
	usec += end.tv_usec - start.tv_usec;
	return (usec);
}

// ---------- CANONICAL CLASS FORM
PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
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

// ------------ MEMBER FUNCTIONS

/* instructions:
   Your program must be able to use a positive integer sequence as argument. */
bool	PmergeMe::parse(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
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

// ---------- CONTAINER LIST
// fill a list of std::pair with elements from _l
void	PmergeMe::fill_list_of_pairs(LIST& big)
{
	std::list<int>::iterator iti = _l.begin();
	std::list<int>::iterator itp = _l.begin();
	int	i = 0;
	int	size = static_cast<int>(_l.size());

	itp++;
	while (i < size / 2)
	{
		if (*iti < *itp)
			big.push_back(std::make_pair(*iti, *itp));
		else
			big.push_back(std::make_pair(*itp, *iti));

		// increment to the next pair
		i++;
		iti++;
		iti++;
		itp++;
		itp++;
	}
}

// applying the merge insertion sort on std::list
void	PmergeMe::sort_list()
{
	// 1 -- group the elements into n/2 pairs and sort each pair
	// 2 -- perform n/2 comparisons to determine the larger of the 2 elements
	int		size = static_cast<int>(_l.size());
	int		last = -1;
	LIST	big;

	fill_list_of_pairs(big);
#ifdef DEBUG
	std::cout << "Unsorted list of pairs: " << std::flush;
	print_list_of_pairs(big);
	std::cout << std::endl;
#endif
	// last element in a odd number of elements
	if (size % 2)
		last = _l.back();

	// 3 -- and recursively sort the n/2 larger elements from each pair
	merge_sort_list(big, 0, static_cast<int>(big.size()) - 1);

	// 3 -- create a sequence S of n/2 of the input elements, in ascending order
	/* std::list<int>	s; */
	_l.clear();
	LIST::iterator	itb = big.begin();
	while (itb != big.end())
	{
		_l.push_back((*itb).second);
		itb++;
	}

	// 4 -- insert at the start of S the element that was paired with
	// the first and smallest element of S
	_l.push_front((big.front()).first);
	big.pop_front();

	// 5 -- insert the remaining n/2 - 1 elements of X into S, one at a time,
	// with a specially chosen insertion ordering
	int	sizeGroup = 0;
	int	nb_of_ele_to_insert;
	int	nb_of_ele_to_erase;
	int	i = 1;
	while (sizeGroup < size && big.empty() == false)
	{
		itb = big.begin();
		sizeGroup = calc_size_group(i++, sizeGroup);
		if (sizeGroup > static_cast<int>(big.size()))
			sizeGroup = static_cast<int>(big.size());
		nb_of_ele_to_insert = sizeGroup;
		nb_of_ele_to_erase = sizeGroup;

		std::advance(itb, nb_of_ele_to_insert - 1);
		while (nb_of_ele_to_insert > 0 && nb_of_ele_to_erase > 0 && big.empty() == false) 
		{
			// insert all elements from current size group ;
			// use a binary search to determine the position
			// at which each element should be inserted
#ifdef DEBUG
			print_list_of_pairs(big);
			std::cout << "iterator pos: " << std::distance(big.begin(), itb) << std::flush;
			std::cout << ", value to insert: " << (*itb).first << std::endl;
			std::cout << "before insertion: " << std::flush;
			print_list(_l);
#endif
			binary_search_insert_list(_l, 0, size - 1, (*itb).first);

#ifdef DEBUG
			std::cout << "after insertion: " << std::flush;
			print_list(_l);
#endif
			nb_of_ele_to_insert--;
			itb--;
			// erase every inserted element from big
			while (nb_of_ele_to_insert == 0 && nb_of_ele_to_erase > 0 && big.empty() == false)
			{
				itb = big.begin();
				big.erase(itb);
				nb_of_ele_to_erase--;
			}
#ifdef DEBUG
			std::cout << "pairs remaining " << std::flush;
			print_list_of_pairs(big);
			std::cout << std::endl;
#endif
		}
	}
	if (last >= 0)
		binary_search_insert_list(_l, 0, size - 1, last);
}

// do a binary search in list to insert val_to_insert in it
void	binary_search_insert_list(std::list<int>& list, int l, int r, int val_to_insert)
{
	/* std::cout << "In binary_search_insert_list" << std::endl; */
	int	m;
	std::list<int>::iterator	it = list.begin();
	while (l <= r)
	{
		m = l + (r - l) / 2;
		/* std::cout << "l=" << l << " , r=" << r << " ,m= " << m << std::endl; */
		it = list.begin();
		std::advance(it, m);
#ifdef DEBUG
		/* print_list(list); */
		/* std::cout << "*it= " << *it << std::endl; */
#endif
		// Check if val_to_insert is present at mid
		if ((*it) == val_to_insert)
		{
			list.insert(it, val_to_insert);
			return ;
		}
		// If val_to_insert greater, ignore left half
		if ((*it) < val_to_insert)
			l = m + 1;
		// If val_to_insert is smaller, ignore right half
		else
			r = m - 1;
	}
	if (*it < val_to_insert)
		it++;
#ifdef DEBUG
	/* std::cout << "iterator pos: " << std::distance(list.begin(), it) << std::endl; */
#endif
	list.insert(it, val_to_insert);
	/* std::cout << "Out binary_search_insert_list\n" << std::endl; */
}

void	PmergeMe::copy_data_to_sublist(LIST &big, LIST& subList, 
		int const pos, int const dataSize)
{
	int	i = 0;
	LIST::iterator	it = big.begin();

	std::advance(it, pos);
	while (i < dataSize)
	{
		subList.push_back(*it);
		it++;
		i++;
	}
}

// Merges two sublists of list.
// First sublist is arr[begin..mid]
// Second sublist is arr[mid+1..end]
void PmergeMe::merge_list(LIST& list, int const left, int const mid,
		int const right)
{
	int const leftListSize = mid - left + 1;
	int const rightListSize = right - mid;

	// Create temp lists
	LIST	leftList;
	LIST	rightList;

	// Copy data to temp lists leftlist and rightlist
	copy_data_to_sublist(list, leftList, left, leftListSize);
	copy_data_to_sublist(list, rightList, mid + 1, rightListSize);

	LIST::iterator	it1 = leftList.begin();
	LIST::iterator	it2 = rightList.begin();
	LIST::iterator	itMerged = list.begin();
	// place the iterator itMerged at the element list.at(left)
	std::advance(itMerged, left);
	// Merge the temp lists back into list[left..right]
	while (it1 != leftList.end() && it2 != rightList.end())
	{
		if ((*it1).second <= (*it2).second)
		{
			itMerged = list.erase(itMerged);
			list.insert(itMerged, *(it1));
			it1++;
		}
		else
		{
			itMerged = list.erase(itMerged);
			list.insert(itMerged, *(it2));
			it2++;
		}
#ifdef DEBUG
		std::cout << "DEBUG for list, after merge, itMerged pos: " << std::distance(list.begin(), itMerged) << std::endl;
#endif
	}

	// Copy the remaining elements of
	// leftList, if there are any
	while (it1 != leftList.end())
	{
		itMerged = list.erase(itMerged);
		list.insert(itMerged, *(it1));
		it1++;
	}

	// Copy the remaining elements of
	// rightList, if there are any
#ifdef DEBUG
	std::cout << "DEBUG for list, after copy leftList, itMerged pos: " << std::distance(list.begin(), itMerged) << std::endl;
#endif
	while (it2 != rightList.end())
	{
		itMerged = list.erase(itMerged);
		list.insert(itMerged, *(it2));
		it2++;
	}
#ifdef DEBUG
	std::cout << "DEBUG for list, after copy rightList, itMerged pos: " << std::distance(list.begin(), itMerged) << std::endl;
#endif
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void PmergeMe::merge_sort_list(LIST& list, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	merge_sort_list(list, begin, mid);
	merge_sort_list(list, mid + 1, end);
	merge_list(list, begin, mid, end);
}


// ----------- CONTAINER VECTOR
void	PmergeMe::sort_vector()
{
	// 1 -- group the elements into n/2 pairs and sort each pair
	// 2 -- perform n/2 comparisons to determine the larger of the 2 elements
	int		size = static_cast<int>(_v.size());
	int		last = -1;
	VECTOR	big;

	fill_vector_of_pairs(big);

	if (size % 2)
		last = _v.back();
	// 3 -- and recursively sort the n/2 larger elements from each pair
	merge_sort_vec(big, 0, static_cast<int>(big.size()) - 1);

	// 3 -- create a sequence S of n/2 of the input elements, in ascending order
	_v.clear();
	VECTOR::iterator	itb = big.begin();
	while (itb != big.end())
	{
		_v.push_back((*itb).second);
		itb++;
	}

	// 4 -- insert at the start of S the element that was paired with
	// the first and smallest element of S
	_v.insert(_v.begin(), (big.front()).first);
	big.erase(big.begin());

	// 5 -- insert the remaining n/2 - 1 elements of X into S, one at a time,
	// with a specially chosen insertion ordering
	int	sizeGroup = 0;
	int	nb_of_ele_to_insert;
	int	nb_of_ele_to_erase;
	int	i = 1;
	while (sizeGroup < size && big.empty() == false)
	{
		itb = big.begin();
		sizeGroup = calc_size_group(i++, sizeGroup);
		if (sizeGroup > static_cast<int>(big.size()))
			sizeGroup = static_cast<int>(big.size());
		nb_of_ele_to_insert = sizeGroup;
		nb_of_ele_to_erase = sizeGroup;

		std::advance(itb, nb_of_ele_to_insert - 1);
		while (nb_of_ele_to_insert > 0 && nb_of_ele_to_erase > 0 && big.empty() == false) 
		{
			// insert all elements from current size group
			// use binary search to determine the position
			// at which each element should be inserted
#ifdef DEBUG
			print_vec_of_pairs(big);
			std::cout << "iterator pos: " << std::distance(big.begin(), itb) << std::flush;
			std::cout << ", value to insert: " << (*itb).first << std::endl;
			std::cout << "before insertion: " << std::flush;
			print_vec(_v);
#endif
			binary_search_insert_vec(_v, 0, size - 1, (*itb).first);

#ifdef DEBUG
			std::cout << "after insertion: " << std::flush;
			print_vec(_v);
#endif
			nb_of_ele_to_insert--;
			itb--;
			// erase every inserted element from big
			while (nb_of_ele_to_insert == 0 && nb_of_ele_to_erase > 0 && big.empty() == false)
			{
				itb = big.begin();
				big.erase(itb);
				nb_of_ele_to_erase--;
			}
#ifdef DEBUG
			std::cout << "pairs remaining " << std::flush;
			print_vec_of_pairs(big);
			std::cout << std::endl;
#endif
		}
	}
	if (last >= 0)
		binary_search_insert_vec(_v, 0, size - 1, last);
}

void	PmergeMe::fill_vector_of_pairs(VECTOR& bigV)
{

	std::vector<int>::iterator iti = _v.begin();
	std::vector<int>::iterator itp = _v.begin();
	int	i = 0;
	int	size = static_cast<int>(_v.size());

	itp++;
	while (i < size / 2)
	{
		if (*iti < *itp)
			bigV.push_back(std::make_pair(*iti, *itp));
		else
			bigV.push_back(std::make_pair(*itp, *iti));

		// increment to the next pair
		i++;
		iti++;
		iti++;
		itp++;
		itp++;
	}
}

void	PmergeMe::merge_sort_vec(VECTOR& vec, int const begin, int const end)
{

	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	merge_sort_vec(vec, begin, mid);
	merge_sort_vec(vec, mid + 1, end);
	merge_vec(vec, begin, mid, end);
}


void	PmergeMe::merge_vec(VECTOR& vec, int const left, int const mid,
		int const right)
{
	int const leftVecSize = mid - left + 1;
	int const rightVecSize = right - mid;

	/* std::cout << "left=" << left << " ,mid=" << mid << " ,right=" << right << std::endl; */
	// Create temp lists
	VECTOR	leftVec;
	VECTOR	rightVec;

	// Copy data to temp lists leftlist and rightlist
	copy_data_to_subvec(vec, leftVec, left, leftVecSize);
	copy_data_to_subvec(vec, rightVec, mid + 1, rightVecSize);

#ifdef DEBUG
	/* std::cout << "Left vec " << std::flush; */
	/* print_vec_of_pairs(leftVec); */
	/* std::cout << "Right vec " << std::flush; */
	/* print_vec_of_pairs(rightVec); */
#endif
	VECTOR::iterator	it1 = leftVec.begin();
	VECTOR::iterator	it2 = rightVec.begin();
	VECTOR::iterator	itMerged = vec.begin();

	std::advance(itMerged, left);
	// Merge the temp lists back into list[left..right]
	while (it1 != leftVec.end() && it2 != rightVec.end())
	{
		if ((*it1).second <= (*it2).second)
		{
			itMerged = vec.erase(itMerged);
			vec.insert(itMerged, *(it1));
			it1++;
		}
		else
		{
			itMerged = vec.erase(itMerged);
			vec.insert(itMerged, *(it2));
			it2++;
		}
		itMerged++;
	}

#ifdef DEBUG
	std::cout << "DEBUG for vec, after merge, itMerged pos: " << std::distance(vec.begin(), itMerged) << std::endl;
#endif
	// Copy the remaining elements of
	// leftVec, if there are any
	while (it1 != leftVec.end())
	{
		itMerged = vec.erase(itMerged);
		vec.insert(itMerged, *(it1));
		itMerged++;
		it1++;
	}

	// Copy the remaining elements of
	// rightVec, if there are any
#ifdef DEBUG
	std::cout << "DEBUG for vec, after left[] copy, itMerged pos: " << std::distance(vec.begin(), itMerged) << std::endl;
#endif
	while (it2 != rightVec.end())
	{
		itMerged = vec.erase(itMerged);
		vec.insert(itMerged, *(it2));
		itMerged++;
		it2++;
	}
#ifdef DEBUG
	std::cout << "DEBUG for vec, after right[] copy, itMerged pos: " << std::distance(vec.begin(), itMerged) << std::endl;
#endif
}


void	PmergeMe::copy_data_to_subvec(VECTOR &bigVec, VECTOR& subvec, 
		int const pos, int const dataSize)
{
	int	i = 0;
	VECTOR::iterator	it = bigVec.begin();

	std::advance(it, pos);
	while (i < dataSize)
	{
		subvec.push_back(*it);
		it++;
		i++;
	}
}

void	binary_search_insert_vec(std::vector<int>& list, int l, int r, int val_to_insert)
{
	/* std::cout << "In binary_search_insert_list" << std::endl; */
	int	m;
	std::vector<int>::iterator	it = list.begin();
	while (l <= r)
	{
		m = l + (r - l) / 2;
		/* std::cout << "l=" << l << " , r=" << r << " ,m= " << m << std::endl; */
		it = list.begin();
		std::advance(it, m);
#ifdef DEBUG
		/* print_list(list); */
		/* std::cout << "*it= " << *it << std::endl; */
#endif
		// Check if val_to_insert is present at mid
		if ((*it) == val_to_insert)
		{
			list.insert(it, val_to_insert);
			return ;
		}
		// If val_to_insert greater, ignore left half
		if ((*it) < val_to_insert)
			l = m + 1;
		// If val_to_insert is smaller, ignore right half
		else
			r = m - 1;
	}
	if (*it < val_to_insert)
		it++;
#ifdef DEBUG
	/* std::cout << "iterator pos: " << std::distance(list.begin(), it) << std::endl; */
#endif
	list.insert(it, val_to_insert);
	/* std::cout << "Out binary_search_insert_list\n" << std::endl; */
}

void	PmergeMe::sort()
{
	struct timeval	start = {0, 0};
	struct timeval	end = {0, 0};
	long int	timerOne = 0;
	long int	timerTwo = 0;
	
	std::cout << "Before: " << std::flush;
	print_vec(_v);
	// time used by algo to sort a vector
	gettimeofday(&start, NULL);
	sort_vector();
	gettimeofday(&end, NULL);
	timerOne = calc_usec(start, end);
	std::cout << "After: " << std::flush;
	print_vec(_v);

	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector : "
		<< timerOne << " us" << std::endl;
	// time used by algo to sort a list
	gettimeofday(&start, NULL);
	sort_list();
	gettimeofday(&end, NULL);
	timerTwo = calc_usec(start, end);
	std::cout << "Time to process a range of " << _v.size() << " elements with std::list : "
		<< timerTwo << " us" << std::endl;
}
