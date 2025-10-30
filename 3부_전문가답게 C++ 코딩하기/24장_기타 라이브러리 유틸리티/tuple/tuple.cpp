#include <iostream>
#include <utility>
#include <tuple>
#include <format>
#include <functional>

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };
	tuple t2{ 3.14, "string 2"s };
	auto t3{ tuple_cat(t1, t2) };
}
