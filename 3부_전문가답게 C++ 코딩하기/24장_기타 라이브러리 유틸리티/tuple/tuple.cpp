#include <iostream>
#include <utility>
#include <tuple>
#include <format>
#include <functional>
#include <compare>

using namespace std;

class Foo
{
	public:
		Foo(string s, int i) : m_str{ move(s) }, m_int{ 1 }
		{
		}

	private:
		int m_int;
		string m_str;
};

int main()
{
	tuple myTuple{ "Hello world", 42 };
	auto foo{ make_from_tuple<Foo>(myTuple) };
}
