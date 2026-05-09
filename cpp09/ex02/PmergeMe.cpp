#include "PmergeMe.hpp"
#include <algorithm>

int comnum = 0;

PmergeMe::PmergeMe() : nbr_of_comps(0)
{
}

PmergeMe::~PmergeMe()
{
}

bool isValidateInput(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		if (str.empty())
			return false;
		for (size_t j = 0; j < str.size(); ++j)
		{
			if (!std::isdigit(str[j]))
				return false;
		}
		std::atoll(str.c_str());
	}
	return true;
}

void printVec(const std::vector< int > &vec, int block_size)
{
	for (int j = 0; j < (int)vec.size(); ++j)
	{
		std::cout << vec[j] << " ";
		if (j % block_size == block_size - 1)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector< int >::iterator findInsertionIndex(std::vector< int > &arr, int target, std::vector< int >::iterator right, int block_size)
{
	std::vector< int >::iterator left = arr.begin();
	std::vector< int >::iterator result_idx = left;
	std::cout << "serching for " << target << " between " << *left << " and " << *right << std::endl;
	while (left <= right)
	{
		int num_blocks = 1 + (right - left) / block_size;
		std::vector< int >::iterator mid = (left + block_size - 1) + ((num_blocks / 2) * block_size);
		if (mid > right)
		{
			mid = right;
		}
		comnum++;
		std::cout << "Comparing...." << std::endl;
		if (*mid < target)
		{
			left = mid + block_size;
			result_idx = left;
		}
		else
		{
			right = mid - block_size;
			result_idx = right + block_size;
		}
	}  // result_idx  an or bn どちらかの位置を指している
	result_idx -= (block_size - 1);
	if (result_idx >= arr.end())
		result_idx = arr.end();
	else if (result_idx < arr.begin())
		result_idx = arr.begin();
	return result_idx;
}

void make_main_chain(std::vector< int > &v, int block_size)
{
	std::vector< int > main_chain;
	std::vector< int > pending_elements;
	std::vector< int > no_pair_elements;
	main_chain.insert(main_chain.end(), v.begin(), v.begin() + block_size * 2);
	size_t i = block_size * 2;
	// ここで、main_chain と pending_elements を作る
	for (size_t j = 0; i + block_size <= v.size(); j++, i += block_size)
	{
		if (j % 2 == 0)	 // bn
		{
			if (i + block_size * 2 >= v.size())
				pending_elements.push_back(-1);
			else
				pending_elements.push_back(v[i + block_size * 2 - 1]);	// anを先頭に挿入
			pending_elements.insert(pending_elements.end(), v.begin() + i, v.begin() + i + block_size);
		}
		else  // an
			main_chain.insert(main_chain.end(), v.begin() + i, v.begin() + i + block_size);
	}
	std::cout << "Main Chain" << std::endl;
	printVec(main_chain, block_size);
	std::cout << "Pending Elements:" << std::endl;
	printVec(pending_elements, block_size + 1);
	if (pending_elements.empty())
		return;
	no_pair_elements.insert(no_pair_elements.end(), v.begin() + i, v.end());
	// std::cout << "No pair elements:" << std::endl;
	// printVec(no_pair_elements, block_size);
	// pending_elements を Jacobsthal 数に従って main_chain に挿入していく
	size_t prev_j = 1;
	size_t curr_j = 3;
	size_t total_b = (pending_elements.size() / (block_size + 1)) + 1;	// bnの総数
	while (prev_j < total_b)
	{
		// 1. 今回のグループでどこまで（どのb_nまで）対象にするか決める
		size_t actual_upper_bound = std::min(curr_j, total_b);
		for (size_t i = actual_upper_bound; i > prev_j; --i)  //
		{
			size_t an_pos = (i - 2) * (block_size + 1);
			size_t bn_pos = an_pos + block_size;
			std::cout << "an = " << pending_elements[an_pos] << " | " << "bn = " << pending_elements[bn_pos] << std::endl;
			std::vector< int >::iterator pos;
			if (pending_elements[an_pos] != -1)
			{
				pos = std::find(main_chain.begin(), main_chain.end(), pending_elements[an_pos]);
				pos -= block_size;
				std::cout << "Found mainchain an-1 or bn  pos: " << *pos << std::endl;
			}
			else
				pos = main_chain.end() - 1;
			std::vector< int >::iterator insert_pos = findInsertionIndex(main_chain, pending_elements[bn_pos], pos, block_size);
			std::vector< int >::iterator pending_elements_pos = pending_elements.begin() + an_pos + 1;
			main_chain.insert(insert_pos, pending_elements_pos, pending_elements_pos + block_size);
			printVec(main_chain, block_size);
		}
		// 3. 次のヤコブ準備
		size_t next_j = curr_j + 2 * prev_j;
		prev_j = curr_j;
		curr_j = next_j;
	}
	std::cout << "After inserting main elements: " << std::endl;
	printVec(main_chain, block_size);
	v.clear();
	v.insert(v.end(), main_chain.begin(), main_chain.end());
	v.insert(v.end(), no_pair_elements.begin(), no_pair_elements.end());
}

void PmergeMe::sortVec(std::vector< int > &v, int block_size)
{
	if (2 * block_size > (int)v.size())
		return;
	for (size_t i = block_size - 1; i + block_size < v.size(); i += 2 * block_size)
	{
		if (v[i] > v[i + block_size])
		{
			// block1: [i - block_size + 1] から [i] まで
			// block2: [i + 1] から [i + block_size] まで
			std::vector< int >::iterator block1_start = v.begin() + (i - block_size + 1);
			std::vector< int >::iterator block1_end = v.begin() + (i + 1);
			std::vector< int >::iterator block2_start = v.begin() + (i + 1);
			std::swap_ranges(block1_start, block1_end, block2_start);
		}
		std::cout << "Comparing...." << std::endl;
		comnum++;
	}
	sortVec(v, block_size * 2);
	// printVec(v, block_size);
	if (block_size * 2 < (int)v.size())
		make_main_chain(v, block_size);
	std::cout << "Total comparisons: " << comnum << std::endl;
}

PmergeMe::PmergeMe(int argc, char *argv[]) : nbr_of_comps(0)
{
	if (!isValidateInput(argc, argv))
	{
		throw std::invalid_argument("Invalid input");
	}
	std::vector< int > v;  //big  a small  b(no pair is -1)
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		v.push_back(num);
	}
	sortVec(v, 1);
}
