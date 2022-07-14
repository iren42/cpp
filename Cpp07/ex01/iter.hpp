
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	print(T const &x) {std::cout << x << std::endl; return ;}

template <typename T>
void	iter(T *addr, size_t length, void (*pFunc)(const T&))
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		pFunc(addr[i]);
		i++;
	}
}



#endif
