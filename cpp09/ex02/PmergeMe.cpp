#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <ctime>

int comnum = 0;

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
void printContainer(const T &container, int block_size)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
		if (std::distance(container.begin(), it) % block_size == block_size - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

template < typename T >
int PmergeMe ::findInsertionIndex(T &container, int target, typename T::iterator right_it, int block_size)
{
	int low = 0;
	int high = ((std::distance(container.begin(), right_it)) + 1);
	int insert_block_idx = 0;
	high /= block_size;
	while (low <= high)
	{
		int mid_block = low + (high - low) / 2;
		typename T::iterator mid_it = my_next(container.begin(), (mid_block * block_size) + (block_size - 1));
		this->_nbr_of_comps++;
		// std::cout << "Comparing target: " << target << " with mid_it: " << *mid_it << std::endl;
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
void PmergeMe ::insertalgorithm(T &main_chain, T &pending_elements, int block_size)
{
	size_t prev_j = 1;
	size_t curr_j = 3;
	size_t total_b = (pending_elements.size() / (block_size + 1)) + 1;	// bnの総数
	while (prev_j < total_b)
	{
		// 1. 今回のグループでどこまで（どのb_nまで）対象にするか決める
		size_t actual_upper_bound = std::min(curr_j, total_b);
		for (size_t i = actual_upper_bound; i > prev_j; --i)
		{
			size_t an_pos = (i - 2) * (block_size + 1);
			size_t bn_pos = an_pos + block_size;
			typename T::iterator an = my_next(pending_elements.begin(), an_pos);
			typename T::iterator bn = my_next(pending_elements.begin(), bn_pos);
			typename T::iterator pos;
			// std::cout << "an = " << *an << " | " << "bn = " << *bn << std::endl;
			if (*an != -1)
			{
				pos = std::find(main_chain.begin(), main_chain.end(), *an);
				// std::cout << "Found mainchain an pos: " << *pos << std::endl;
				pos = my_prev(pos, block_size);
				// std::cout << "Found mainchain an-1 or bn  pos: " << *pos << std::endl;
			}
			else
				pos = my_prev(main_chain.end(), 1);
			int insert_block_idx = findInsertionIndex(main_chain, *bn, pos, block_size);
			typename T::iterator pending_elements_pos = my_next(pending_elements.begin(), an_pos + 1);
			typename T::iterator insert_pos = my_next(main_chain.begin(), insert_block_idx * block_size);
			main_chain.insert(insert_pos, pending_elements_pos, my_next(pending_elements_pos, block_size));
			// printContainer(main_chain, block_size);
		}
		// 3. 次のヤコブ準備
		size_t next_j = curr_j + 2 * prev_j;
		prev_j = curr_j;
		curr_j = next_j;
	}
	// std::cout << "After inserting main elements: " << std::endl;
	// printContainer(main_chain, block_size);
}

template < typename T >
void PmergeMe ::make_main_chain(T &container, int block_size)
{
	T main_chain;
	T pending_elements;
	T no_pair_elements;
	typename T::iterator main_chain_end = my_next(container.begin(), block_size * 2);
	main_chain.insert(main_chain.end(), container.begin(), main_chain_end);
	size_t i = block_size * 2;
	// main_chain と pending_elements 作成
	for (size_t j = 0; i + block_size <= container.size(); j++, i += block_size)
	{
		if (j % 2 == 0)	 // bn
		{
			if (i + block_size * 2 >= container.size())
				pending_elements.push_back(-1);
			else
			{
				typename T::iterator it = my_next(container.begin(), (i + block_size * 2 - 1));
				pending_elements.push_back(*it);  // anを先頭に挿入
			}
			pending_elements.insert(pending_elements.end(), my_next(container.begin(), i), my_next(container.begin(), i + block_size));
		}
		else  // an
			main_chain.insert(main_chain.end(), my_next(container.begin(), i), my_next(container.begin(), i + block_size));
	}
	// std::cout << "Main Chain" << std::endl;
	// printContainer(main_chain, block_size);
	// std::cout << "Pending Elements:" << std::endl;
	// printContainer(pending_elements, block_size + 1);
	if (pending_elements.empty())
		return;
	no_pair_elements.insert(no_pair_elements.end(), my_next(container.begin(), i), container.end());
	/// ヤコブの挿入アルゴリズム
	insertalgorithm(main_chain, pending_elements, block_size);
	container.clear();
	container.insert(container.end(), main_chain.begin(), main_chain.end());
	container.insert(container.end(), no_pair_elements.begin(), no_pair_elements.end());
}

template < typename T >
void PmergeMe ::sortContainer(T &container, int block_size)
{
	if (block_size == 1)
		this->_nbr_of_comps = 0;
	if (2 * block_size > (int)container.size())
		return;
	for (size_t i = block_size - 1; i + block_size < container.size(); i += 2 * block_size)
	{
		typename T::iterator it_i = my_next(container.begin(), (i));
		typename T::iterator it_ipb = my_next(it_i, block_size);
		this->_nbr_of_comps++;
		if (*it_i > *it_ipb)
		{
			// block1: [i - block_size + 1] から [i] まで
			// block2: [i + 1] から [i + block_size] まで
			typename T::iterator block1_start = my_next(container.begin(), (i - block_size + 1));
			typename T::iterator block1_end = my_next(container.begin(), (i + 1));
			typename T::iterator block2_start = my_next(container.begin(), (i + 1));
			std::swap_ranges(block1_start, block1_end, block2_start);
		}
		// std::cout << "Comparing...." << std::endl;
	}
	sortContainer(container, block_size * 2);
	if (block_size * 2 < (int)container.size())
		make_main_chain(container, block_size);
	// std::cout << "Total comparisons: " << comnum << std::endl;
}

void printResults(std::clock_t start, std::clock_t end, std::string container_type, int elements)
{
	double duration = static_cast< double >(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << elements << " elements with std:: " << container_type << " : " << duration * 1e6 << " us" << std::endl;
}

void printAfterbar(const std::vector< int > &vect)
{
	std::cout << "After: ";
	for (size_t i = 0; i < vect.size(); ++i)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << " (" << vect.size() << " elements)" << std::endl;
}
PmergeMe ::PmergeMe() : _nbr_of_comps(0)
{
}

PmergeMe ::~PmergeMe()
{
}

PmergeMe ::PmergeMe(int argc, char *argv[]) : _nbr_of_comps(0)
{
	std::vector< int > vect;
	std::list< int > lst;
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		vect.push_back(num);
		lst.push_back(num);
	}
	// vector
	std::clock_t start = std::clock();
	sortContainer(vect, 1);
	std::clock_t end = std::clock();
	printAfterbar(vect);
	printResults(start, end, "vector", vect.size());
	std::cout << "Comparisons: " << this->_nbr_of_comps << std::endl;
	//
	/// list
	start = std::clock();
	sortContainer(lst, 1);
	end = std::clock();
	printResults(start, end, "list", lst.size());
	std::cout << "Comparisons: " << this->_nbr_of_comps << std::endl;
	//
}
