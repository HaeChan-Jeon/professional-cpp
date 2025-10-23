#include <iostream>
#include <utility>

using namespace std;

int main()
{
	pair<string, int> myPair{ "hello", 5 };
	pair<string, int> myOtherPair;

	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	pair<string, int> myThirdPair{ myOtherPair };

	pair myPair2{ "hello"s, 5 };

	pair<int, double> pair1{ make_pair(5, 10.10) };
	auto pair2{ make_pair(5, 10.10) };
	pair pair3{ 5, 10.10 };
}