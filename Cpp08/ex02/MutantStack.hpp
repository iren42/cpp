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
		typedef typename std::stack<T>::container_type::iterator iterator;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator begin(void) { return this->c.begin(); }
		iterator  end(void)   { return this->c.end(); }

reverse_iterator rend(void) {  return this->c.rend(); }
reverse_iterator rbegin(void) {  return this->c.rbegin(); }
 
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
