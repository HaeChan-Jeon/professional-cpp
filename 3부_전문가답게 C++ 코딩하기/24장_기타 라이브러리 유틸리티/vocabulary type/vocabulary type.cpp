#include <variant>
#include <string>
#include <iostream>

using namespace std;

class MyVisitor
{
public:
    void operator()(int i) { cout << "int " << i << endl; }
    void operator()(const string& s) { cout << "string " << s << endl; }
    void operator()(float f) { cout << "float " << f << endl; }
};

int main()
{
    variant<int, string, float> v;
    // 디폴트 생성이 다 안 된다면?
    //variant<monostate, int, string, float> v;

    v = 12;
    v = 12.5f;
    v = "An std::string"s;

    cout << "Type index: " << v.index() << endl;
    cout << "Contains an int: " << holds_alternative<int>(v) << endl;
    cout << "Contains an int: " << holds_alternative<string>(v) << endl;

    cout << get<string>(v) << endl;
    try {
        cout << get<0>(v) << endl;
    } catch (const bad_variant_access& ex) {
        cout << "Exception: " << ex.what() << endl;
    }

    string* theString{ get_if<string>(&v) };
    int* theInt{ get_if<int>(&v) };
    cout << "retrieved string: " << (theString ? *theString : "null") << endl;
    cout << "retrieved int: " << (theInt ? *theInt : 0) << endl;

    visit(MyVisitor(), v);
}
