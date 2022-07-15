#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack<T> const &rhs);
		virtual ~MutantStack();
		MutantStack<T> &operator=(MutantStack<T> const &other);
/*
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	begin() { return this->c.begin(c); }
	iterator	end() { return this->c.end(c); }

	const_iterator	begin() const { return this->c.cbegin(c); }
	const_iterator	end() const { return this->c.cend(c); }*/

};


template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack()
{
}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
	(*this) = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::cout << "MutantStack Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		operator=(other);
	}
	return (*this);
}


#endif
