#ifndef PERMGEME_HPP
#define PERMGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// pairを作る
//

struct Element
{
	int a;	// 比較対象となる値
			// 前のステップで負けた要素や、付随する情報を保持する
};
class PmergeMe
{
private:
	/* data */
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	int nbr_of_comps;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(int argc, char *argv[]);
	void sortVec(std::vector< int > &vec, int i);
};

#endif