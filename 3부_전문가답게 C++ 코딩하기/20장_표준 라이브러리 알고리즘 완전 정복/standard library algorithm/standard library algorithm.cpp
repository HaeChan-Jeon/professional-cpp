#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

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
	int x{ 4 }, y{ 5 };
	cout << format("x is {} and y is {}", x, y) << endl;
	cout << "Max is " << max(x, y) << endl;
	cout << "Min is " << min(x, y) << endl;

	// 두 개 이상의 값에 대해 max()와 min()을 구하는 예
	int x1{ 2 }, x2{ 9 }, x3{ 3 }, x4{ 12 };
	cout << "Max of 4 elements is " << max({ x1, x2, x3, x4 }) << endl;
	cout << "Min of 4 elements is " << min({ x1, x2, x3, x4 }) << endl;

	// minmax()를 구하는 예
	auto p2{ minmax({x1, x2, x3, x4}) };
	cout << format("Minmax of 4 elements is <{}, {}>", p2.first, p2.second) << endl;

	// minmax()와 C++17부터 지원하는 구조적 바인딩을 적용하는 예
	auto[min1, max1] { minmax({x1, x2, x3, x4}) };
	cout << format("Minmax of 4 elements is <{}, {}>", min1, max1) << endl;

	// minmax_element()와 C++17부터 지원하는 구조적 바인딩을 적용하는 예
	vector values{ 11, 22, 33 };
	auto [min2, max2] { minmax_element(cbegin(values), cend(values)) };
	cout << format("Minmax_element() result: <{}, {}>", *min2, *max2) << endl;
}