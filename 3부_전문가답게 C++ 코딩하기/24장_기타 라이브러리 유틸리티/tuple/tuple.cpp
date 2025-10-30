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
}
