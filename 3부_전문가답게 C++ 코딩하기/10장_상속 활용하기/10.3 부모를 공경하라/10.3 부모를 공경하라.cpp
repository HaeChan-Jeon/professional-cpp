#include <iostream>

using namespace std;

class Something
{
    public:
        Something() { cout << "2"; }
};

class Base
{
    public:
        //Base() { cout << "1"; }
        Base(int i) { cout << i; };
};

class Derived : public Base
{
    public:
        Derived() : Base { 7 } { cout << "3"; }
    //private:
    //    Something m_dataMember;
};

int main()
{
    Derived myDerived;
}