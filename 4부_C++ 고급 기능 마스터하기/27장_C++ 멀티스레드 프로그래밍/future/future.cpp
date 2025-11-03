#include <iostream>
#include <future>
#include <thread>

using namespace std;

int calculate() {
    throw runtime_error{ "Exception throw from calculate()." };
}

int main()
{
    // 강제로 비동기식으로 실행하도록 launch::async 정책을 지정한다.
    auto myFuture{ async(launch::async, calculate) };

    // 다른 작업을 수행한다.

    // 결과를 가져온다.
    try {
        int result{ myFuture.get() };
        cout << result << endl;
    }
    catch (const exception& ex) {
        cout << "Caught exception: " << ex.what() << endl;
    }
}