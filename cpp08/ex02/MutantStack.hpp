#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>
#include <deque>

template < typename T >
class MutantStack : public std::stack< T, std::deque< T > >
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();
	typedef typename std::stack< T >::container_type::iterator iterator;
	typedef typename std::stack< T >::container_type::const_iterator const_iterator;
	iterator end();
	iterator begin();
	const_iterator end() const;
	const_iterator begin() const;
};

#include "MutantStack.tpp"

#endif
