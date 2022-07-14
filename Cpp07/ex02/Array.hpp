#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_elements;
		int	_size;

	public:
		virtual ~Array();
		Array();
		Array(int size);
		Array(const Array &rhs);
		Array &operator = (const Array &rhs);

		int	getSize() const;
		T	&operator [] (int position) const;


};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &rhs);

/* IMPLEMENTATION */


	template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Destructor called" << std::endl;
	delete [] _elements;
}

	template <typename T>
Array<T>::Array() : _elements(0), _size(0)

{
	std::cout << "Array Default constructor called" << std::endl;
}

	template <typename T>
Array<T>::Array(int size) :  _elements(new T[size]), _size(size)
{
	std::cout << "Array Default constructor called" << std::endl;
	int	i = 0;
	while (i < _size)
	{
		_elements[i] = T();
		i++;
	}
}


	template <typename T>
Array<T>::Array(const Array &other)
{
	std::cout << "Array Copy constructor called" << std::endl;
	_size = other._size;
	_elements = 0;
	*this = other;
}

	template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Array Copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		if (this->_elements != 0)
			delete [] _elements;
		_elements = new T[other._size];
		_size = other._size;
		int	i = 0;
		while (i < _size)
		{
			_elements[i] = other._elements[i];
			i++;
		}
	}
	return (*this);
}


template <typename T>
int	Array<T>::getSize() const
{
	return (_size);
}

template <typename T>
T &Array<T>::operator [] (int position) const
{
	if (position >= _size)
		throw (std::exception());
	return (this->_elements[position]);
}


	template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &rhs)
{
	const int	size = rhs.getSize();
	int	i = 0;
	os << "[";
	while (i < size)
	{
		os << rhs[i];
		if (i < size - 1)
			os << ", ";
		i++;

	}
	os << "]";
	return (os);
}
#endif
