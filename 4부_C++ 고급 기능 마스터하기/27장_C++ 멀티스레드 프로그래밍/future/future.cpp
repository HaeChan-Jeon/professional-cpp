#include <iostream>
#include <future>
#include <thread>

using namespace std;

int calculate() { return 123; }

int main()
{
    auto myFuture{ async(calculate) };

    // 다른 작업을 수행한다.

    // 결과를 가져온다.
    int result{ myFuture.get() };
    cout << "Result: " << result << endl;
}