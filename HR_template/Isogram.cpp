#include "Isogram.hpp"

using namespace std;

Isogram::Isogram(std::string str) {

	initUMap(this->charMap);
	initTestedStr(str);
}

// Initialize a hash table from a-z and init the value to 0
void Isogram::initUMap(std::unordered_map<char, int> &u_map) {
	for (char i = 'a'; i <= 'z'; i++)
		u_map.insert({ i, {0} });

}

void Isogram::initTestedStr(std::string str) {
	//insert the string to be tested then put it in lower case to avoid extra computations
	this->testedString = str;
	this->lowerCaseIso();

	//start the checking of the tested string
	this->is_isogram();

}

// check the count of each letter of the string then determines if it is an isogram
void Isogram::is_isogram() {	
	for (auto i : this->testedString) {
		this->incrementValue(i);
	}

	this->printResult(checkIso());
}

// increment the hash table for each letters found in the tested string
void Isogram::incrementValue(int pos) {
	this->charMap[pos]++;
}

// check the hash table to determine if the tested str is an isogram
bool Isogram::checkIso() {
	for (auto a : this->charMap) {
		if (a.second > 1)
			return false;
	}
	return true;
}

// put the tested string into lowercases to avoid extra computation and confusion --> e.g.: D != d
void Isogram::lowerCaseIso() {
	transform(this->testedString.begin(), this->testedString.end(), this->testedString.begin(), ::tolower);
}

void Isogram::printResult(bool result)
{
	if (result)
		std::cout << this->getStr() << " is an isogram." << endl;
	else
		std::cout << this->getStr() << " is not an isogram." << endl;

}
