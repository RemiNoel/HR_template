#ifndef FIND_MISSING_ARRAY_H
#define FIND_MISSING_ARRAY_H

#include <vector>

namespace FindMissArr {

	template<class TYPE>
	int fct(std::vector<std::vector<TYPE>>);

	template<class TYPE>
	int getLengthOfMissingArray(std::vector<std::vector<TYPE>>);


	template<class TYPE>
	std::vector<std::vector<TYPE>> input;

}


#endif