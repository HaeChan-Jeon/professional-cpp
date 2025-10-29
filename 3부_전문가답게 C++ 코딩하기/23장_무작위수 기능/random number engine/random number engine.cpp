#include <iostream>
#include <random>
#include <functional>
#include <vector>

using namespace std;

void fillVector(vector<int>& values, const auto& generator)
{
	generate(begin(values), end(values), generator);
}

int main()
{
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };

	uniform_int_distribution<int> distribution{ 1, 99 };

	cout << distribution(engine) << endl;

	auto generator{ bind(distribution, engine) };

	vector<int> values(10);
	//generate(begin(values), end(values), generator);
	fillVector(values, generator);

	for (auto i : values) { cout << i << " "; }
}