#ifndef PERMGEME_HPP
#define PERMGEME_HPP

#include <string>
#include <ctime>
#include <sys/time.h>
template < typename T >

class PmergeMe
{
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	int _nbr_of_comps;
	T _container;
	std::string _container_type;
	struct timeval _start_time;
	struct timeval _end_time;

	void sortContainer(int block_size);
	int findInsertionIndex(T &container, int target, typename T::iterator right_it, int block_size);
	void insertalgorithm(T &main_chain, T &pending_elements, int block_size);
	void make_main_chain(int block_size);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(int argc, char *argv[], T container, std::string container_type);
	void printContainer(int block_size);
	void printResults();
	int getNbrOfComps() const;
};

#include "PmergeMe.cpp"
//#include "PmergeMe.tpp"

#endif
