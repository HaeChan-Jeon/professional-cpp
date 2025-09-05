#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a{ "12" };
    string b{ "34" };
    string c;
    c = a + b;

    cout << c << endl << endl;

    a += b;
    cout << a << endl << endl;

    const char* a2{ "12" };
    char b2[]{ "12" };

    if (!(a2 == b2)) { cout << false << endl << endl; }
    if (strcmp(a2, b2) == 0) { cout << true << endl << endl; }

    string a3{ "12" };
    string b3{ "34" };

    auto result{ a3.compare(b3) };
    if (result < 0) { cout << "ress" << endl; }
    if (result > 0) { cout << "greater" << endl; }
    if (result == 0) { cout << "equal" << endl; }

    auto result2{ a3 <=> b3 };
    if (is_lt(result2)) { cout << "ress" << endl; }
    if (is_gt(result2)) { cout << "greater" << endl; }
    if (is_eq(result2)) { cout << "equal" << endl; }

    cout << endl;

    string myString{ "hello" };
    myString += ", there";
    string myOtherString{ myString };
    if (myString == myOtherString) {
        myOtherString[0] = 'H';
    }
    cout << myString << endl;
    cout << myOtherString << endl;

    //스트링 연산
    string strHello{ "Hello!!" };
    string strWorld{ "The World..." };
    auto position{ strHello.find("!!") };
    if (position != string::npos) {
        strHello.replace(position, 2, strWorld.substr(3, 6));
    }
    cout << strHello << endl;

    //std::string 리터널
    auto string1{ "Hello World" };  // string1의 타입은 const char*다.
    auto string2{ "Hello World"s }; // string2의 타입은 std::string이다.

    //std::vector와 스트링의 CATD
    vector names1{ "John", "Sam", "Joe" };
    vector names2{ "John"s, "Sam"s, "Joe"s };
}