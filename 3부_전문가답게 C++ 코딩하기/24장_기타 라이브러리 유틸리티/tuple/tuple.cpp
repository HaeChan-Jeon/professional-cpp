#include <iostream>
#include <utility>
#include <tuple>
#include <format>
#include <functional>
#include <compare>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << apply(add, tuple{ 39, 3 }) << endl;
}
