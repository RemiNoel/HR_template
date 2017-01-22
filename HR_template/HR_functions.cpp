#include "HR_functions.hpp"

// Finds the element that is singular in a vector (can only be one for this version)
int HR_functions::lonelyInteger(std::vector<int>& a) {
	if (a.size() % 2 != 1) {
		std::cout << "Incorrect vector size(). Size() has to be an odd number!" << std::endl;
		return -1;
	}

	int result = 0;
	// find the lonely int
	/*
	if there's only one lonely integer, a XOR can be used to isolate it.
	e.g. : 1 ^ 1 = 0
	1 ^ 2 = 3 ---> 3 ^ 2 = 1
	5 ^ 2 = 7 ---> 7 ^ 5 = 2

	*/
	for (unsigned int j = 0; j < a.size(); j++)
		result = result ^ a.at(j);

	return result;
}

// find the pair of min and max value of the sum of every elements in a vector minus an element of the vector 
HR_functions::minMax HR_functions::minMaxFunc(std::vector<long long>& vec) {
	minMax result;
	result.min = 0, result.max = 0;
	int index = 1;
	long long temp = 0;
	long long constantTemp = 0;

	constantTemp = (long long)std::accumulate(vec.begin(), vec.end(), 0.0);

	//init the values to be compared to
	result.min = constantTemp - vec.at(0);
	result.max = constantTemp - vec.at(0);

	while (index != vec.size()) {
		temp = constantTemp - vec.at(index);
		if (temp > result.max)
			result.max = temp;
		else if (temp < result.min && temp > 0)
			result.min = temp;
		index++;
		temp = constantTemp;
	}
	return result;
}

// substract the lowest value in a vector to all elements of the vector until vector is of size 1
void HR_functions::cutTheSticks(std::vector<int>& vec) {
	int lowest{ 10001 };
	int result{ 0 };
	int tempLowest{ 10001 };

	//sort the vector
	std::sort(vec.begin(), vec.end());

	// find the lowest value of the vector to be used for "cutting the sticks"
	lowest = vec.at(0);

	/*
	   1. as long as the size of the vector is not 1, keep going
	   2. Substract the value of lowest from each elements of the vector
	   3. Remove the elements that are equal or less than zero and resize vector accordingly
	   4. find the lowest value of the vector to be used for "cutting the sticks"
	   5. print the size of the vector (
	   5. check back condition 1.
	*/
	std::cout << vec.size() << std::endl;

	while (std::find(vec.begin(), vec.end(), lowest) != vec.end() && vec.size() != 1) {

		for (int i = 0; i != vec.size(); i++)
			vec.at(i) -= lowest;
		
		vec.erase(std::remove_if(vec.begin(), vec.end(), [](const int& i) {return i <= 0; }), vec.end());
		lowest = vec.at(0);
		std::cout << vec.size() << std::endl;
	}

}

// Search for the index of a specific wanted number and returns it
int HR_functions::findIndex_BinSearch(std::vector<int> vec, int number, int beginIndex, int endIndex){
	if (vec.size() == 0)
		return -1;

	int middleIndex = (beginIndex + endIndex) / 2;
	
	if (vec.at(middleIndex) == number)
		return middleIndex;
	else if (vec.at(middleIndex) < number)
		return HR_functions::findIndex_BinSearch(vec, number, middleIndex + 1, endIndex);
	else if (vec.at(middleIndex) > number)
		return HR_functions::findIndex_BinSearch(vec, number, beginIndex, middleIndex - 1);
	else
		return -1;
}

// Normal insertion sort algorithm
void HR_functions::insertionSort(std::vector<int> vec) {
	int i = 0, j = 0;
	int temp;

	while (i != vec.size()) {
		j = i;
		while (j > 0 && vec.at(j) < vec.at(j - 1)) {
			temp = vec.at(j);
			vec.at(j) = vec.at(j - 1);
			vec.at(j - 1) = temp;
			j--;
		}
		++i;
	}
}

/*
For each test case, print  lines containing the formatted , , and , respectively. Each , , and  must be formatted as follows:

A: Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the prefix) in lower case letters.
B: Print it to a scale of  decimal places, preceded by a  or  sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly  characters wide.
C: Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
*/
void HR_functions::pprint() {
	int T; std::cout << "How many loops of input (A, B, C) do you want? "; std::cin >> T;
	while (T--) {
		std::ios_base::fmtflags flags = std::cout.flags();

		double A; std::cout << "A: "; std::cin >> A;
		double B; std::cout << "B: "; std::cin >> B;
		double C; std::cout << "C: "; std::cin >> C;
		
		//reset output flags
		std::cout.flags(flags);

		/* Output format
		A. 0x64             
		B. _______+2006.01  
		C. 2.331415927E+03
		
		*/

		// A
		std::cout.flags(flags);
		std::cout << std::setw(0) << std::showbase << std::hex << std::nouppercase << (long long)(A) << std::endl;

		// B
		std::cout.flags(flags);
		std::cout << std::fixed << std::right << std::setfill('_') << std::setw(15) << std::setprecision(2) << std::showpos << B << std::endl;

		// C
		std::cout.flags(flags);
		std::cout << std::setiosflags(std::ios::uppercase) << std::scientific << std::setprecision(9) << C << std::endl;
	}
}

// Fibonacci sequence dealing with very large numbers (F(n) = F(n-1) + F(n-2)²
boost::multiprecision::int128_t HR_functions::modifiedFibo(boost::multiprecision::int128_t n) {
	if (n < 0 || n > 20)
		return -1;

	if (n == 0 )
		return 0;
	if (n == 1 || n == 2)
		return 1;

	return modifiedFibo(n - 1) + pow(modifiedFibo(n - 2), 2);
}

// Finds the minimum value of needed items to buy depending on the values of scores
__int64 HR_functions::minItems(std::vector<int>& scores) {
	// the value of the sum of all needed items
	__int64  minOfItems = 0;
	//Initialize the container of items (Left to right trend)
	std::vector<int> candyQuantLeft(scores.size(), 1);
	// Initialize the container of items (Right to left trend)
	std::vector<int> candyQuantRight(scores.size(), 1);

	// Check trend from left to right
	for (unsigned int i = 1; i < scores.size(); ++i) {
		if (scores.at(i) > scores.at(i - 1))
			candyQuantLeft.at(i) = candyQuantLeft.at(i - 1) + 1;
	}

	// Check trend from right to left
	for (int i = scores.size() - 2; i >= 0; --i) {
		if (scores.at(i) > scores.at(i + 1))
			candyQuantRight.at(i) = candyQuantRight.at(i + 1) + 1;
	}

	// For it to be correct, we need to find the max value of items to give from each trends
	// That is, if we only check in one side, it could be possible that a student has a higher score 
	// than the one on its right but has not been rewarded correctly.
	for (unsigned int i = 0; i < scores.size(); ++i)
		minOfItems += std::max(candyQuantLeft[i], candyQuantRight[i]);

	return minOfItems;
}


// Find the largest array in a 2D-array
template<class TYPE>
int HR_functions::FindMissArr::findLargestArr(std::vector<std::vector<TYPE>> arrOfArr) {
	int tempSz = 0;
	for (int i = 0; i < arrOfArr.size(); ++i) {
		if (tempSz < arrOfArr[i].size())
			tempSz = arrOfArr[i].size();
	}
	return tempSz;
}

// Finds the missing array in a 2D array (e.g. 2D array contains arrays of size : 2,5,3,1 --> the missing array is of size 4
template<class TYPE>
int HR_functions::FindMissArr::getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
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


// Find the max difference in length between the length of min and max strings
static int HR_functions::MaxLengthDiff::mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2) {
	//Find max(abs(length(x) − length(y)))
	if (a1.empty() || a2.empty())
		return -1;

	int maxLgS1 = HR_functions::MaxLengthDiff::largestString(a1);
	int maxLgS2 = HR_functions::MaxLengthDiff::largestString(a2);

	int minLgS1 = HR_functions::MaxLengthDiff::smallestString(a1);
	int minLgS2 = HR_functions::MaxLengthDiff::smallestString(a2);

	int temp1 = abs(maxLgS2 - minLgS1);
	int temp2 = abs(maxLgS1 - minLgS2);

	return std::max(temp1, temp2);
}

// Returns the longest string from a vector of strings
static int HR_functions::MaxLengthDiff::largestString(std::vector<std::string> &s) {
	unsigned int temp = 0;
	for (int i = 0; i != s.size(); i++) {
		if (temp < s[i].length())
			temp = s[i].length();
	}
	return temp;
}

// Returns the shortest string from a vector of strings
static int HR_functions::MaxLengthDiff::smallestString(std::vector<std::string> &s) {
	unsigned int temp = 999999999;
	for (int i = 0; i != s.size(); i++) {
		if (temp > s[i].length())
			temp = s[i].length();
	}
	return temp;
}


