#include <iostream>
#include <future>
#include <thread>

using namespace std;

int main()
{
    promise<void> thread1Started, thread2Started;

    promise<int> signalPromise;
    auto signalFuture{ signalPromise.get_future().share() };

    auto function1{ [&thread1Started, signalFuture] {
        thread1Started.set_value();
        // 매개변수가 설정될 때까지 기다린다.
        int pamameter{ signalFuture.get() };
        // ...
    } };

    auto function2{ [&thread2Started, signalFuture] {
    thread2Started.set_value();
    // 매개변수가 설정될 때까지 기다린다.
    int pamameter{ signalFuture.get() };
    // ...
    } };

    // 두 람다 표현식을 비동기식으로 구동한다.
    // async()에서 리턴한 future를 까먹지 말고 캡쳐한다.
    auto result1{ async(launch::async, function1) };
    auto result2{ async(launch::async, function2) };

    // 두 스레드 모두 구동될 때까지 기다린다.
    thread1Started.get_future().wait();
    thread2Started.get_future().wait();

    // 이제 두 스레드 모두 매개변수가 설정되기를 기다린다.
    // 두 스레드를 깨우는 매개변수를 설정한다.
    signalPromise.set_value(42);
}