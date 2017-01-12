#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

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