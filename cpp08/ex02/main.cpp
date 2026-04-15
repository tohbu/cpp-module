#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{
	MutantStack< int > mstack;
	mstack.push(5);
	mstack.push(17);
	std ::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack< int >::iterator it = mstack.begin();
	MutantStack< int >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	//list test
	std::list< int > list;
	list.push_back(5);
	list.push_back(17);
	list.pop_back();
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::cout << "list test" << std::endl;
	for (std::list< int >::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	//
	std::stack< int > s(mstack);
	const MutantStack< int > const_mstack(mstack);
	s.push(42);
	s.push(84);
	s.pop();
	std::cout << "stack top: " << s.top() << std::endl;
	if (!const_mstack.empty())
	{
		std::cout << "const mutant stack begin: " << *const_mstack.begin() << std::endl;
		MutantStack< int >::const_iterator last = const_mstack.end();
		--last;
		std::cout << "const mutant stack last: " << *last << std::endl;
	}
	return 0;
}