#include <iostream>
#include <utility>
#include <tuple>
#include <format>

using namespace std;

int main()
{
	pair<int, string> p1{ 16, "Hello World!" };
	pair p2{ true, 0.123f };
	cout << format("p1 = ({}, {})", p1.first, p1.second) << endl;
	cout << format("p2 = ({}, {})", p2.first, p2.second) << endl;

	using MyTuple = tuple<int, string, bool>;
	MyTuple t1{ 16, "Test", true };

	cout << format("t1 = ({}, {}, {})", get<0>(t1), get<1>(t1), get<2>(t1)) << endl;

	cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

	cout << "Type of element with index 2 = "
		<< typeid(tuple_element<2, MyTuple>::type).name() << endl;

	cout << "String = " << get<string>(t1) << endl;
}
