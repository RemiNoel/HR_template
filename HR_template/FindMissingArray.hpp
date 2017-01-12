#ifndef FIND_MISSING_ARRAY_HPP
#define FIND_MISSING_ARRAY_HPP

#include <vector>

namespace FindMissArr {

	template<class TYPE>
	int findLargestArr(std::vector<std::vector<TYPE>>);

	template<class TYPE>
	int getLengthOfMissingArray(std::vector<std::vector<TYPE>>);

	template<class TYPE>
	std::vector<std::vector<TYPE>> input;

}


#endif