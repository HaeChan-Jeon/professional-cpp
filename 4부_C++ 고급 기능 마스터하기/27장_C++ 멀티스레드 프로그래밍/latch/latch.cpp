#include <iostream>
#include <latch>
#include <vector>
#include <thread>

using namespace std;

int main()
{
	latch startLatch{ 1 };
	vector<jthread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(jthread{ [&startLatch] {
			// 초기화 작업을 수행한다(CPU 바운드).

			// 래치 카운터가 0에 도달할 때까지 기다린다.
			startLatch.wait();


			// 데이터를 처리한다.
		} });
	}

	// 데이터를 불러온다(I/O 바운드).

	// 데이터를 모두 불러왔다면 래치 카운터를 감소시킨다.
	// 카운터가 0에 도달하면 블록된 스레드를 모두 해제시킨다.
	startLatch.count_down();
}
