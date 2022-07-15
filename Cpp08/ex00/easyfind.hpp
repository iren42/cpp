#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator> // for iterators
# include <vector> // for vectors
# include <algorithm>
# include <list>

template <typename T>
bool	easyfind(T &container, int tofind);



/* IMPLEMENTATION */

template <typename T>
bool	easyfind(T &container, int tofind)
{
	if (std::find(container.begin(), container.end(), tofind) != container.end())
		return (1);
	return (0);
}
#endif
