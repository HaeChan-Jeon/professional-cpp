#include <iostream>
#include <functional>
#include <span>
#include <format>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <string_view>
#include <unordered_set>

using namespace std::string_view_literals;
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
//
//template <typename Iter, typename StartValue, typename Operation>
//auto accumulateData(Iter begin, Iter end, StartValue startValue, Operation op)
//{
//	auto accumulated{ startValue };
//	for (Iter iter{ begin }; iter != end; ++iter) {
//		accumulated = op(accumulated, *iter);
//	}
//	return accumulated;
//}
//
//double geometricMeanTransparent(span<const int> values)
//{
//	auto mult{ accumulateData(cbegin(values), cend(values), 1.1, multiplies<>{}) };
//	return pow(mult, 1.0 / values.size());
//}

class Hasher
{
public:
	using is_transparent = void;
	size_t operator()(string_view sv) const { return hash<string_view>{}(sv); }
};

int main()
{
	//vector values1{ 2, 500, 6, 9, 10, 101, 1 };
	//vector values2{ 4, 4, 2, 9, 0, 300, 1 };
	//findMatches(values1, values2, IsLargerThan { 100 }, &printMatch);

	//plus<int> myPlus;
	//int res{ myPlus(4, 5) };
	//cout << res << endl;

	priority_queue<int, vector<int>, greater<>> myQueue;

	set<string> mySet;
	auto i1{ mySet.find("Key") };
	// auto i2 { mySet.find("Key"sv) }; // 이렇게 하면 컴파일 에러가 발생함

	// 이종 룩업
	set<string, less<>> mySet2;
	auto i2{ mySet2.find("Key") };
	auto i3{ mySet2.find("Key"sv) };

	unordered_set<string, Hasher, equal_to<>> mySet3;
	auto i4{ mySet3.find("Key") };
	auto i5{ mySet3.find("Key"sv) };

}