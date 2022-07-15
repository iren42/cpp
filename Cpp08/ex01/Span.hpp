#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector> // for vectors
#include <algorithm> 
#include <iterator>
#include <bits/stdc++.h>

class Span
{
	private:
		unsigned int _N;
		std::vector<int>	_v;

	public:
		~Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator = (const Span &other);

		void	addNumber(int num);
		int	shortestSpan();
		int	longestSpan();
		void	display() ;
		std::vector<int> getVec();
		void setVec(std::vector<int> v);

// Exception classes
		class	CustomException : public std::exception
	{
		private:
			std::string	_msg;

		public:
			const char	*what() const throw ();
			~CustomException() throw();
			CustomException(std::string msg);
	};
};

std::vector<int>	range_add_with_rand(unsigned long size); // creates new vector with <size> numbers
#endif
