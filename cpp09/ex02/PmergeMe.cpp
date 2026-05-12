#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <sys/time.h>
#include <iomanip>
#include "PmergeMe.hpp"

template < typename Iterator, typename Distance >
Iterator my_next(Iterator it, Distance n)
{
	std::advance(it, n);
	return it;
}

template < typename Iterator, typename Distance >
Iterator my_prev(Iterator it, Distance n)
{
	std::advance(it, -n);
	return it;
}

template < typename T >
void PmergeMe< T >::printContainer(int block_size)
{
	for (typename T::iterator it = _container.begin(); it != _container.end(); ++it)
	{
		std::cout << *it << " ";
		if (std::distance(_container.begin(), it) % block_size == block_size - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template < typename T >
void printSTL(T &container, int block_size)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
		if (std::distance(container.begin(), it) % block_size == block_size - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template < typename T >
int PmergeMe< T >::findInsertionIndex(T &container, int target, typename T::iterator right_it, int block_size)
{
	int low = 0;
	int high = std::distance(container.begin(), right_it) / block_size;
	int insert_block_idx = 0;
	while (low <= high)
	{
		int mid_block = low + (high - low) / 2;
		typename T::iterator mid_it = my_next(container.begin(), (mid_block * block_size) + (block_size - 1));
		this->_nbr_of_comps++;
		if (*mid_it < target)
		{
			low = mid_block + 1;
			insert_block_idx = low;
		}
		else
		{
			high = mid_block - 1;
			insert_block_idx = mid_block;
		}
	}
	return insert_block_idx;
}

template < typename T >
void PmergeMe< T >::insertalgorithm(T &main_chain, T &pending_elements, int block_size)
{
	size_t prev_j = 1;
	size_t curr_j = 3;
	size_t total_b = (pending_elements.size() / (block_size + 1)) + 1;
	while (prev_j < total_b)
	{
		size_t actual_upper_bound = std::min(curr_j, total_b);
		for (size_t i = actual_upper_bound; i > prev_j; --i)
		{
			size_t an_pos = (i - 2) * (block_size + 1);
			size_t bn_pos = an_pos + block_size;
			typename T::iterator an = my_next(pending_elements.begin(), an_pos);
			typename T::iterator bn = my_next(pending_elements.begin(), bn_pos);
			typename T::iterator right;
			if (*an != -1)
			{
				right = std::find(main_chain.begin(), main_chain.end(), *an);
				right = my_prev(right, block_size);
			}
			else
				right = my_prev(main_chain.end(), 1);

			//Debug output
			//std::cout << "an = " << *an << "	|  bn = " << *bn << "	| right = " << *right << std::endl;
			int insert_block_idx = findInsertionIndex(main_chain, *bn, right, block_size);
			typename T::iterator pending_elements_pos = my_next(pending_elements.begin(), an_pos + 1);
			typename T::iterator insert_pos = my_next(main_chain.begin(), insert_block_idx * block_size);
			main_chain.insert(insert_pos, pending_elements_pos, my_next(pending_elements_pos, block_size));
		}
		size_t next_j = curr_j + 2 * prev_j;
		prev_j = curr_j;
		curr_j = next_j;
	}
}

template < typename T >
void PmergeMe< T >::make_main_chain(int block_size)
{
	T main_chain;
	T pending_elements;
	T no_pair_elements;
	typename T::iterator main_chain_end = my_next(_container.begin(), block_size * 2);
	main_chain.insert(main_chain.end(), _container.begin(), main_chain_end);
	size_t i = block_size * 2;
	for (size_t j = 0; i + block_size <= _container.size(); j++, i += block_size)
	{
		if (j % 2 == 0)	 // bn
		{
			if (i + block_size * 2 > _container.size())
				pending_elements.push_back(-1);
			else
			{
				typename T::iterator it = my_next(_container.begin(), (i + block_size * 2 - 1));
				pending_elements.push_back(*it);
			}
			pending_elements.insert(pending_elements.end(), my_next(_container.begin(), i), my_next(_container.begin(), i + block_size));
		}
		else  // an
			main_chain.insert(main_chain.end(), my_next(_container.begin(), i), my_next(_container.begin(), i + block_size));
	}
	if (pending_elements.empty())
		return;
	// //Debug output
	// std::cout << "Main chain:" << std::endl;
	// printSTL(main_chain, block_size);
	// std::cout << "Pending elements: " << std::endl;
	// printSTL(pending_elements, block_size + 1);

	no_pair_elements.insert(no_pair_elements.end(), my_next(_container.begin(), i), _container.end());
	insertalgorithm(main_chain, pending_elements, block_size);
	_container.clear();
	_container.insert(_container.end(), main_chain.begin(), main_chain.end());
	_container.insert(_container.end(), no_pair_elements.begin(), no_pair_elements.end());
	// //Debug output
	// std::cout << "After inserting pending elements: " << std::endl;
	// printSTL(_container, block_size);
}

template < typename T >
void PmergeMe< T >::sortContainer(int block_size)
{
	if (2 * block_size > (int)_container.size())
		return;
	for (size_t i = block_size - 1; i + block_size < _container.size(); i += 2 * block_size)
	{
		typename T::iterator it_i = my_next(_container.begin(), i);
		typename T::iterator it_ipb = my_next(it_i, block_size);
		this->_nbr_of_comps++;
		if (*it_i > *it_ipb)
		{
			typename T::iterator block1_start = my_next(_container.begin(), (i - block_size + 1));
			typename T::iterator block1_end = my_next(_container.begin(), (i + 1));
			typename T::iterator block2_start = my_next(_container.begin(), (i + 1));
			std::swap_ranges(block1_start, block1_end, block2_start);
		}
	}
	sortContainer(block_size * 2);
	if (block_size * 2 < (int)_container.size())
		make_main_chain(block_size);
}

template < typename T >

void PmergeMe< T >::printResults()
{
	double start_us = static_cast< double >(this->_start_time.tv_sec) * 1000000.0 + static_cast< double >(this->_start_time.tv_usec);
	double end_us = static_cast< double >(this->_end_time.tv_sec) * 1000000.0 + static_cast< double >(this->_end_time.tv_usec);
	double duration = end_us - start_us;
	std::cout << "Time to process a range of " << _container.size()
			  << " elements with std::" << _container_type << ": "
			  << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
	// //Debug output
	// std::cout << "Number of comparisons: " << this->_nbr_of_comps << std::endl;
}

template < typename T >
int PmergeMe< T >::getNbrOfComps() const
{
	return this->_nbr_of_comps;
}

template < typename T >
PmergeMe< T >::PmergeMe() : _nbr_of_comps(0)
{
}

template < typename T >
PmergeMe< T >::~PmergeMe()
{
}

template < typename T >
PmergeMe< T >::PmergeMe(int argc, char *argv[], T container, std::string container_type) : _nbr_of_comps(0), _container(container), _container_type(container_type)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		this->_container.push_back(num);
	}
	gettimeofday(&this->_start_time, NULL);
	sortContainer(1);
	gettimeofday(&this->_end_time, NULL);
}
