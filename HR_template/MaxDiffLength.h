#ifndef MAX_DIFF_LENGTH_H
#define MAX_DIFF_LENGTH_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class MaxDiffLength
{
public:
	MaxDiffLength() {};
	
	static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2);
	static int largestString(std::vector<std::string> &s);
	static int smallestString(std::vector<std::string> &s);

};



#endif