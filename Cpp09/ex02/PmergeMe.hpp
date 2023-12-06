#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <algorithm>

# define ERR_ARG "Error: not enough arguments."
# define ERR_INPUT "Error: input not valid."

# define LIST std::list<std::pair<int, int>>

class PmergeMe
{
	private:
		PmergeMe();
		std::list<int>	_l;
		std::vector<int>	_v;

		static bool	is_zero(std::string &s); // for the parsing
		static bool	is_a_posi_num(std::string& word); // for the parsing

		void	sort_list();
		void	sort_vector();
void	merge_sort(LIST& list, int const begin, int const end);
void	merge(LIST& list, int const left, int const mid, int const right);
void	copy_data_to_sublist(LIST &bigList, LIST& subList, 
		int const pos, int const dataSize);
bool	larger_ele_are_sorted(LIST&);

	public:
		~PmergeMe();
		PmergeMe(int, char**);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		static bool	parse(int, char**);

		void	print_list(std::list<int>&);
void	print_list_of_pairs(LIST& l);
		void	print_vector();

		void	sort();
};


#endif
