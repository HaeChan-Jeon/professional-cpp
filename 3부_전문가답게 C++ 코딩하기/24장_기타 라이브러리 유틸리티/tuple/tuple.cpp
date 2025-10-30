#include <iostream>
#include <utility>
#include <tuple>
#include <format>
#include <functional>

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

	cout << "Tuple Size = " << tuple_size<MyTuple>::value << endl;
	
	cout << "Tuple Size = " << tuple_size<decltype(t1)>::value << endl;

	//tuple t1{ 16, "Test"s, true };

	double d{ 3.14 };
	string str1{ "Test" };
	tuple t2{ 16, ref(d), cref(d), ref(str1) };

	cout << "d = " << d << endl;
	get<1>(t2) *= 2;
	cout << "d = " << d << endl;

	auto t2{ make_tuple(16, ref(d), cref(d), ref(str1)) };
}
