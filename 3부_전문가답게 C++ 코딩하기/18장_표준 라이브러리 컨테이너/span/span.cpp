#include <iostream>
#include <vector>
#include <span>
#include <array>

using namespace std;

void print(const vector<int>& values)
{
    for (const auto& value : values) { cout << value << " "; }
    cout << endl;
}

void print(const int values[], size_t count)
{
    for (size_t i{ 0 }; i < count; ++i) { cout << values[i] << " "; }
    cout << endl;
}

void print(span<const int> values)
{
    for (const auto& value : values) { cout << value << " "; }
    cout << endl;
}

int main()
{
    vector v{ 11, 22, 33, 44, 55, 66 };
    print(v);

    span mySpan{ v };
    print(mySpan);

    span subSpan{ mySpan.subspan(2, 3) };
    print(subSpan);

    print({ v.data() + 2, 3 });

    array<int, 5> arr{ 5, 4, 3, 2, 1 };
    print(arr);
    print({ arr.data() + 2, 3 });

    int carr[]{ 9, 8, 7, 6, 5 };
    print(carr);
    print({ carr + 2, 3 });
}