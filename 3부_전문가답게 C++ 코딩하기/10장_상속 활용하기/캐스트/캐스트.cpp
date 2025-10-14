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
	Base* b;
	Derived* d = { new Derived{} };
	b = d;
	d = dynamic_cast<Derived*>(b);
}