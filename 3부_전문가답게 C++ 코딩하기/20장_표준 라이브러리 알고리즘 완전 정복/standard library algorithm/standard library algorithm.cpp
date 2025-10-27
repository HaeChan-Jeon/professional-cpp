#include <numeric>
#include <span>

using namespace std;

int product(int value1, int value2) { return value1 * value2; }

double geometricMean(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, product) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanLamda(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1,
		[](int value1, int value2) { return value1 * value2; }) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanFunctor(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}

int main()
{
}