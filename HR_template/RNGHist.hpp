#ifndef RNGHist_HPP
#define RNGHist_HPP

#include <random>
#include <iostream>

/*
	Interface of RNGHist class
	Class used to create the instance of an RNG histogram based on a Mersenne Twister engine (mt19937)
*/

using namespace std;

class RNGHist{
public:
	RNGHist() {};
	RNGHist(int low, int max);
	
	// Draw an int from the distribution
	int operator ()() { return dist(re); }
	void printHist(int max);

private:
	mt19937 make_seeded_engine();

	default_random_engine re = make_seeded_engine();
	uniform_int_distribution<> dist;
};
#endif
