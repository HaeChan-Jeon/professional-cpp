#include <iostream>
#include <barrier>
#include <vector>
#include <thread>

using namespace std;

void completionFunction() noexcept {}

int main()
{
	const size_t numberOfThreads{ 4 };
	barrier barrierPoint{ numberOfThreads, completionFunction };
	vector<jthread> threads;

	for (int i{ 0 }; i < numberOfThreads; ++i) {
		threads.push_back(jthread{ [&barrierPoint](stop_token token) {
			while (!token.stop_requested()) {
				// 계산을 수행한다.

				// 다른 스레드와 동기화한다.
				barrierPoint.arrive_and_wait();
			}
		} });
	}
}
