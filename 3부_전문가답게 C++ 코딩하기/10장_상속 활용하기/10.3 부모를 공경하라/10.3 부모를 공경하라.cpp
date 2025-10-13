#include <iostream>

using namespace std;

class Something
{
    public:
        Something() { cout << "2"; }
        //virtual ~Something() { cout << "2"; }
        ~Something() { cout << "2"; }
};

class Base
{
    public:
        Base() { cout << "1"; }
        //virtual ~Base() { cout << "1"; }
        ~Base() { cout << "1"; }
};

class Derived : public Base
{
    public:
        Derived() { cout << "3"; }
        //virtual ~Derived() { cout << "3"; }
        ~Derived() { cout << "3"; }
    private:
        Something m_dataMember;
};

int main()
{
    //Derived myDerived;
    Base* ptr{ new Derived{} };
    delete ptr;
}