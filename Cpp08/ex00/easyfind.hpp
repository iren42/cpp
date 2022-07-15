#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator> // for iterators
# include <vector> // for vectors
# include <algorithm>
# include <list>

template <typename T>
void	easyfind(T &container, int tofind);



/* IMPLEMENTATION */

template <typename T>
void	easyfind(T &container, int tofind)
{
	if (std::find(container.begin(), container.end(), tofind) != container.end())
		std::cout << "Found: " << tofind << std::endl;
	else
		throw (std::exception());
}
#endif
