#ifndef MAX_DIFF_LENGTH_HPP
#define MAX_DIFF_LENGTH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

/*
	Interface of MaxDiffLength 
	This class is used to find the maximum value of the difference in length of the strings in 2 vectors of strings
*/

class MaxDiffLength
{
public:
	MaxDiffLength() {};
	
	static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2);
	static int largestString(std::vector<std::string> &s);
	static int smallestString(std::vector<std::string> &s);

};

#endif
