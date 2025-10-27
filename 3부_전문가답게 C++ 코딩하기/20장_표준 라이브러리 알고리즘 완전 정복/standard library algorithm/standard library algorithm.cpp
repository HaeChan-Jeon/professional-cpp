#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <format>
#include <execution>

using namespace std;

template<typename Container>
void polulateContainter(Container& cont)
{
	while (true) {
		cout << "Enter a number (0 to quit): ";
		int value;
		cin >> value;
		if (value == 0) { break; }
		cont.push_back(value);
	}
}

template <typename Iterator>
void DumpRange(string_view message, Iterator begin, Iterator end)
{
	cout << message;
	for_each(begin, end, [](const auto& element) { cout << element << " "; });
	cout << endl;
}

int main()
{
	vector<int> values(10);
	iota(begin(values), end(values), 5);
	for (auto& i : values) { cout << i << " "; }
}