#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <format>

using namespace std;

atomic_flag spinlock = ATOMIC_FLAG_INIT;
static const size_t NumberOfThreads{ 50 };
static const size_t LoopsPerThread{ 100 };

void dowork(size_t threadNumber, vector<size_t>& data)
{
	for (size_t i{ 0 }; i < LoopsPerThread; ++i) {
		while (spinlock.test_and_set()) { }
		data.push_back(threadNumber);
		spinlock.clear();
	}
}

int main()
{
	vector<size_t> data;
	vector<thread> threads;
	for (size_t i{ 0 }; i < NumberOfThreads; ++i) {
		threads.push_back(thread{ dowork, i, ref(data) });
	}
	for (auto& t : threads) {
		t.join();
	}
	cout << format("data contains {} element, excepted {}.\n", data.size(),
		NumberOfThreads * LoopsPerThread);
}