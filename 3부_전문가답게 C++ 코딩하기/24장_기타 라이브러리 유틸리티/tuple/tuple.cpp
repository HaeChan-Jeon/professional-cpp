#include <iostream>
#include <utility>
#include <tuple>
#include <format>
#include <functional>

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };
	auto [i, str, b] { t1 };
	cout << format("Decomposed: i = {}, str = \"{}\", b = {}", i, str, b) << endl;

	auto& [i2, str2, b2] { t1 };
	i2 *= 2;
	str2 = "Hello World";
	b2 = !b2;
	cout << format("Decomposed: i = {}, str = \"{}\", b = {}", i2, str2, b2) << endl;

	int i3{ 0 };
	string str3;
	bool b3{ false };
	cout << format("Before: i = {}, str = \"{}\", b = {}", i3, str3, b3) << endl;
	tie(i3, str3, b3) = t1;
	cout << format("After: i = {}, str = \"{}\", b = {}", i3, str3, b3) << endl;

	tie(i, ignore, b) = t1;
}
