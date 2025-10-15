#include <iostream>;

namespace
{
	void f();

	void f()
	{
		std::cout << "f\n";
	}
}

int x{ 4 };

extern int y{ 3 };