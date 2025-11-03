#include <semaphore>
#include <vector>
#include <thread>

using namespace std;

int main()
{
	counting_semaphore semaphore{ 4 };
	vector<jthread> threads;
	for (int i{0}; i < 10; ++i) {
		threads.push_back(jthread{ [&semaphore] {
			semaphore.acquire();

			semaphore.release();
		} });
	}
}