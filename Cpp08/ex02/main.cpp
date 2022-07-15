/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 07:51:43 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/15 12:33:43 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void displayStack(std::stack<int> s)
{
	while(!s.empty()) {
		std::cout<< s.top()<<" ";
		s.pop();
	}
	std::cout << std::endl;
}

int	main()
{
	// TEST 1: test from subject
	std::cout << "TEST 1" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "display mstack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;	
	// TEST 2: testing reverse_iterator
	{
		std::cout << "TEST 2" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		std::cout << "display mstack in reverse order with reverse iterator" << std::endl;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
		std::cout << std::endl;	
	}
	// TEST 3 : copy assign
	{
		std::cout << "TEST 3" << std::endl;
		MutantStack<int> m;
		m = mstack;
		MutantStack<int>::iterator t3 = m.begin();
		MutantStack<int>::iterator te3 = m.end();
		std::cout << "display the copy of mstack" << std::endl;
		while (t3 != te3)
		{
			std::cout << *t3 << std::endl;
			++t3;
		}
		m.pop();
		m.pop();
		m.pop();
		t3 = m.begin();
		te3 = m.end();
		std::cout << "display copy after multiple calls to pop()" << std::endl;
		while (t3 != te3)
		{
			std::cout << *t3 << std::endl;
			++t3;
		}
	}
	std::cout << "redisplay mstack after the copy is deleted" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// TEST 4 : copy constructor
	{
		std::cout << "TEST 4" << std::endl;
		MutantStack<int> m(mstack);
		MutantStack<int>::iterator t3 = m.begin();
		MutantStack<int>::iterator te3 = m.end();
		std::cout << "display the copy of mstack" << std::endl;
		while (t3 != te3)
		{
			std::cout << *t3 << std::endl;
			++t3;
		}
		m.push(41);
		m.push(42);
		m.push(43);
		t3 = m.begin();
		te3 = m.end();
		std::cout << "display the copy after multiple calls to push()" << std::endl;
		while (t3 != te3)
		{
			std::cout << *t3 << std::endl;
			++t3;
		}
		std::cout << "redisplay mstack after the copy is deleted" << std::endl;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
