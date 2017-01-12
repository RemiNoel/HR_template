#include "RNGHist.hpp"

// Constructor
RNGHist::RNGHist(int low, int max) : dist{ low, max } {
	RNGHist::printHist(max);
}

// Print a histogram using the distribution and the RNG engine
void RNGHist::printHist(int max) {
	vector<int> histogram(max + 1);

	for (int i = 0; i <= 200; ++i)
		++histogram[this->operator()()];

	for (int i = 0; i != histogram.size(); i++) {
		cout << i << "\t";

		for (int j = 0; j != histogram[i]; j++)
			cout << "*";

		cout << endl;
	}
}

// Seed the RNG engine
mt19937 RNGHist::make_seeded_engine() {
	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };
	return std::mt19937(seed);
}