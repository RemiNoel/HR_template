#include "FindMissingArray.hpp"

// Find the largest array in a 2D-array
template<class TYPE>
int FindMissArr::findLargestArr(std::vector<std::vector<TYPE>> arrOfArr) {
	int tempSz = 0;
	for (int i = 0; i < arrOfArr.size(); ++i) {
		if (tempSz < arrOfArr[i].size())
			tempSz = arrOfArr[i].size();
	}
	return tempSz;
}

// Finds the missing array in a 2D array (e.g. 2D array contains arrays of size : 2,5,3,1 --> the missing array is of size 4
template<class TYPE>
int FindMissArr::getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
	if (arrayOfArrays.size() == 0)
		return 0;

	for (int i = 0; i < arrayOfArrays.size(); ++i)
		if (arrayOfArrays[i].size() == 0)
			return 0;

	// returns the largest size of subarrays
	int largestSize = findLargestArr(arrayOfArrays);

	// sum from [1:n] = (n + (n + 1)) / 2
	int tempExpected = (largestSize * (largestSize + 1)) / 2;

	int tempActual = 0;
	for (int i = 0; i < arrayOfArrays.size(); ++i)
		tempActual += arrayOfArrays[i].size();

	if (tempExpected == tempActual)
		return 0;
	else
		return tempExpected - tempActual;

	return 0;
}
