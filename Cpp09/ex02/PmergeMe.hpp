#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <algorithm>

# define ERR_ARG "Error: not enough arguments."
# define ERR_INPUT "Error: input not valid."

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
void	list_recursive_sort(std::list<std::pair<int, int>>&);
bool	larger_ele_are_sorted(std::list<std::pair<int, int>>&);

	public:
		~PmergeMe();
		PmergeMe(int, char**);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		static bool	parse(int, char**);

		void	print_list(std::list<int>&);
		void	print_vector();

		void	sort();
};


#endif
