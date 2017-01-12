#ifndef ISOGRAM_HPP
#define ISOGRAM_HPP

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

/*
	Interface of Isogram class
	Class used to determine if a string is an Isogram 
	What is an isogram? -> https://en.wikipedia.org/wiki/Isogram
*/

class Isogram {
public:
	Isogram(std::string str);
	void initUMap(std::unordered_map<char, int> &u_map);
	void initTestedStr(std::string str);

	std::string getStr() { return this->testedString; }

	void is_isogram();
	void incrementValue(int pos);
	bool checkIso();
	void printResult(bool result);
	void lowerCaseIso();


private:
	std::unordered_map<char, int> charMap;
	std::string testedString;
};

#endif