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
		Foo(int i, string s, bool b) : m_int{ 1 }, m_str{ move(s) }, m_bool{ b }
		{
		}
		auto operator<=>(const Foo& rhs) const = default;

	private:
		int m_int;
		string m_str;
		bool m_bool;
};

int main()
{
	tuple t1{ 123, "def"s };
	tuple t2{ 123, "abc"s };
	if (t1 < t2) {
		cout << "t1 < t2" << endl;
	} else {
		cout << "t1 >= t2" << endl;
	}

	Foo f1{ 42, "Hello", false };
	Foo f2{ 42, "World", false };
	cout << (f1 < f2) << endl;
	cout << (f2 < f1) << endl;
}
