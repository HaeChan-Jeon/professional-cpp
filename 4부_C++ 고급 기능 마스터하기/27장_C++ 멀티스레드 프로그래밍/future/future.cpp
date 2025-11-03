#include <iostream>
#include <future>
#include <thread>

using namespace std;

void doWork(promise<int> thePromise)
{
    // 원하는 작업을 한다.
    // 최종 결과를 promise에 저장한다.
    thePromise.set_value(42);
}

int main()
{
    // 스레드에 전달할 promise를 생성한다.
    promise<int> myPromise;
    // 이 promise에 대한 futre를 가져온다.
    auto theFuture{ myPromise.get_future() };
    // 스레드를 생성하고 앞에서 만든 promise를 인수로 전달한다.
    thread theThread{ doWork, std::move(myPromise) };

    // 원하는 작업을 수행한다.

    // 최종 결과를 가져온다.
    int result{ theFuture.get() };
    cout << "Result: " << result << endl;

    // 스레드를 join한다.
    theThread.join();
}