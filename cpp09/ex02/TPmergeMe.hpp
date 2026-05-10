#ifndef TPERMGEME_HPP
#define TPERMGEME_HPP

#include <string>

template < typename T >

class PmergeMe
{
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	int _nbr_of_comps;
	T _container;
	void sortContainer(int block_size);
	int findInsertionIndex(T &container, int target, typename T::iterator right_it, int block_size);
	void insertalgorithm(T &main_chain, T &pending_elements, int block_size);
	void make_main_chain(int block_size);

public:
	PmergeMe() : _nbr_of_comps(0) {};
	~PmergeMe() {};
	PmergeMe(int argc, char *argv[], T container, std::string container_type);
	T getContainer() const
	{
		return _container;
	}
	void printContainer(const T &container, int block_size);
};

#include "TPmergeMe.tpp"

#endif