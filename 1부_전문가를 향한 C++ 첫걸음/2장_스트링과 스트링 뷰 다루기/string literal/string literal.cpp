#include <iostream>

using namespace std;

int main()
{
    cout << "hello" << endl;
    cout << endl;

    char arr[]{ "hello" };
    arr[1] = 'a';
    cout << arr << endl;
    cout << endl;

    // 로 스트링 리터널
    const char* str{ "Hello \"World\"!" };
    cout << str << endl;
    cout << endl;

    const char* str1{ R"(Hello "World"!)" };
    cout << str1 << endl;
    cout << endl;

    const char* str2{ "Line 1\nLine 2" };
    cout << str2 << endl;
    cout << endl;

    const char* str3{ R"(Line 1
Line 2)" };
    cout << str3 << endl;
    cout << endl;

    const char* str4{ R"(Is the following a tab character? \t)" };
    cout << str4 << endl;
    cout << endl;

    const char* str5{ R"-(Embedded )" characters)-" };
    cout << str5 << endl;
    cout << endl;
}