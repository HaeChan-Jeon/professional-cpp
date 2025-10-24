#include <iostream>
#include <functional>
#include <span>
#include <format>
#include <vector>
#include <cmath>

using namespace std;

//using Matcher = function<bool(int, int)>;
//
//using MatchHandler = function<void(size_t, int, int)>;
//
//bool intEqual(int item1, int item2) { return item1 == item2; }
//
//void printMatch(size_t position, int value1, int value2)
//{
//	cout << format("Match found at position {} ({}, {})",
//		position, value1, value2) << endl;
//}
//
//template<typename Matcher, typename MatchHandler>
//void findMatches(span<const int> values1, span<const int> values2,
//	Matcher matcher, MatchHandler handler)
//{
//	if (values1.size() != values2.size()) { return; }
//
//	for (size_t i{ 0 }; i < values1.size(); ++i) {
//		if (matcher(values1[i], values2[i])) {
//			handler(i, values1[i], values2[i]);
//		}
//	}
//}
//
//class IsLargerThan
//{
//public:
//    explicit IsLargerThan(int value) : m_value{ value } {}
//    bool operator()(int value1, int value2) const {
//        return value1 > m_value && value2 > m_value;
//    }
//private:
//    int m_value;
//};

template <typename Iter, typename StartValue, typename Operation>
auto accumulateData(Iter begin, Iter end, StartValue startValue, Operation op)
{
	auto accumulated{ startValue };
	for (Iter iter{ begin }; iter != end; ++iter) {
		accumulated = op(accumulated, *iter);
	}
	return accumulated;
}

double geometricMeanTransparent(span<const int> values)
{
	auto mult{ accumulateData(cbegin(values), cend(values), 1.1, multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}

int main()
{
	//vector values1{ 2, 500, 6, 9, 10, 101, 1 };
	//vector values2{ 4, 4, 2, 9, 0, 300, 1 };
	//findMatches(values1, values2, IsLargerThan { 100 }, &printMatch);

	plus<int> myPlus;
	int res{ myPlus(4, 5) };
	cout << res << endl;
}