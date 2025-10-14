#include <iostream>

using namespace std;

class Base
{
	public:
		virtual ~Base() = default;
};

class Derived : public  Base
{
	public:
		virtual ~Derived() = default;
};

int main()
{
	Base base;
	Derived derived;
	Base& br{ base };
	try {
		Derived& dr{ dynamic_cast<Derived&>(br) };
	}
	catch (const bad_cast&)	{
		cout << "Bad cast!" << endl;
	}
}