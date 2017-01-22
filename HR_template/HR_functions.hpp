#ifndef HR_FUNCTIONS_HPP
#define HR_FUNCTIONS_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>

#include <boost/multiprecision/cpp_int.hpp>



// Namespace for functions used to solve various Hackerrank.com problems


namespace HR_functions {

	namespace FindMissArr {
		template<class TYPE>
		int findLargestArr(std::vector<std::vector<TYPE>>);

		template<class TYPE>
		int getLengthOfMissingArray(std::vector<std::vector<TYPE>>);

		template<class TYPE>
		std::vector<std::vector<TYPE>> input;
	}

	namespace MaxLengthDiff {
		static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2);
		static int largestString(std::vector<std::string> &s);
		static int smallestString(std::vector<std::string> &s);
	}

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

	__int64 minItems(std::vector<int>& scores);

}

#endif // ! HR_FUNCTIONS_HPP

