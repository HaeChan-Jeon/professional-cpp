#include <iostream>

class Base
{
	public:
		virtual ~Base() = default;
};

class Derived : public Base
{
	public:
		virtual ~Derived() = default;
};

int main()
{
	Base* b{ nullptr };
	Derived* d{ new Derived{} };
	b = d; // 상속 계층의 상위 타입으로 업캐스트할 필요 없다.
	d = static_cast<Derived*>(b); // 상속 계층의 하위 타입으로 다운캐스트해야 한다.

	Base base;
	Derived derived;
	Base& br{ derived };
	Derived& dr{ static_cast<Derived&>(br) };
}