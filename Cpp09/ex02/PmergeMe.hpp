#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <algorithm>
# include <sys/time.h>
# include <ctime>

# define ERR_ARG "Error: not enough arguments."
# define ERR_INPUT "Error: input not valid."

# define LIST std::list<std::pair<int, int> >
# define VECTOR std::vector<std::pair<int, int> >

long unsigned int	calc_size_group(int i, long unsigned int prevSizeGroup);
void	binary_search_insert_list(std::list<int>& list, int l, int r, int val_to_insert);
void	binary_search_insert_vec(std::vector<int>& list, int l, int r, int val_to_insert);
void	get_time(struct timeval& tv);

// print functions
void	print_list(std::list<int>& myList);
void	print_vec(std::vector<int>& v);
void	print_list_of_pairs(LIST& l);
void	print_vec_of_pairs(VECTOR& l);

class PmergeMe
{
	private:
		PmergeMe();
		std::list<int>	_l;
		std::vector<int>	_v;

		static bool	is_zero(std::string &s); // for the parsing
		static bool	is_a_posi_num(std::string& word); // for the parsing

		// for std::list
		void	sort_list();
		void	merge_sort_list(LIST& list, int const begin, int const end);
		void	merge_list(LIST& list, int const left, int const mid,
				int const right);
		void	copy_data_to_sublist(LIST &bigList, LIST& subList, 
				int const pos, int const dataSize);
		void	fill_list_of_pairs(LIST& bigList);

		// for std::vector
		void	sort_vector();
		void	fill_vector_of_pairs(VECTOR& bigV);
		void	merge_sort_vec(VECTOR& vec, int const begin, int const end);
		void	merge_vec(VECTOR& vec, int const left, int const mid,
				int const right);
		void	copy_data_to_subvec(VECTOR &bigvec, VECTOR& subvec, 
				int const pos, int const dataSize);

	public:
		~PmergeMe();
		PmergeMe(int, char**);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);

		static bool	parse(int, char**);

		void	sort();
};


#endif
