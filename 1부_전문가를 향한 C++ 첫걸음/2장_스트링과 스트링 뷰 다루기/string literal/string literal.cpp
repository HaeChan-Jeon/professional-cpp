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
}