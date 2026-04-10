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
	const MutantStack< int > const_mstack(mstack);
	std::cout << "const mutant stack begin: " << *const_mstack.begin() << std::endl;
	std::cout << "const mutant stack end: " << *(const_mstack.end()) << std::endl;
	return 0;
}