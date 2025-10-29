#include <iostream>
#include <random>
#include <functional>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	const unsigned int Start{ 1 };
	const unsigned int End{ 99 };
	const unsigned int Iterations{ 1'000'000 };

	// 균등 메르센 트위스터
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	uniform_int_distribution<int> distribution{ Start, End };
	auto generator{ bind(distribution, engine) };
	map<int, int> histogram;
	for (unsigned int i{ 0 }; i < Iterations; ++i) {
		int randomNumber{ generator() };
		++(histogram[randomNumber]);
	}
	
	ofstream of{ "res.csv" };
	for (unsigned i{ Start }; i <= End; ++i) {
		of << i << "," << histogram[i] << endl;
	}
}