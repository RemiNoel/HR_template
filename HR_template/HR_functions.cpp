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


