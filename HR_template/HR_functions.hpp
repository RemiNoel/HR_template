#ifndef  HR_FUNCTIONS_HPP
#define HR_FUNCTIONS_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>

#include <boost/multiprecision/cpp_int.hpp>


/*
	Namespace for functions used to solve various Hackerrank.com problems
*/

namespace HR_functions {

	struct minMax {
		long long min;
		long long max;
	};

	int lonelyInteger(std::vector<int>& vec);

	minMax minMaxFunc(std::vector<long long>& vec);

	void cutTheSticks(std::vector<int>& vec);

	int findIndex_BinSearch(std::vector<int> vec, int number, int beginIndex, int endIndex);

	void insertionSort(std::vector<int> vec);

	void pprint();

	boost::multiprecision::int128_t modifiedFibo(boost::multiprecision::int128_t n);

}

#endif // ! HR_FUNCTIONS_HPP

