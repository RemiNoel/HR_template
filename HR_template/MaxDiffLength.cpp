#include "MaxDiffLength.hpp"

// Find the mi
int MaxDiffLength::mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2) {
	//Find max(abs(length(x) − length(y)))
	if (a1.empty() || a2.empty())
		return -1;

	int maxLgS1 = MaxDiffLength::largestString(a1);
	int maxLgS2 = MaxDiffLength::largestString(a2);

	int minLgS1 = MaxDiffLength::smallestString(a1);
	int minLgS2 = MaxDiffLength::smallestString(a2);

	 int temp1 = abs(maxLgS2 - minLgS1);
	 int temp2 = abs(maxLgS1 - minLgS2);

	 return std::max(temp1, temp2);
}

int MaxDiffLength::largestString(std::vector<std::string> &s) {
	unsigned int temp = 0;
	for (int i = 0; i != s.size(); i++) {
		if (temp < s[i].length()) 
			temp = s[i].length();
	}
	return temp;
}

int MaxDiffLength::smallestString(std::vector<std::string> &s) {
	unsigned int temp = 999999999;
	for (int i = 0; i != s.size(); i++) {
		if (temp > s[i].length())
			temp = s[i].length();
	}
	return temp;
}
