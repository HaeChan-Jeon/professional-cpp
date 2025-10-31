#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <format>

using namespace std;

once_flag g_onceFlag;
void initializeSharedResources()
{
	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	call_once(g_onceFlag, initializeSharedResources);
	cout << "Processing" << endl;
}

int main()
{
	vector<thread> threads{ 3 };
	for (auto& t : threads) {
		t = thread{ processingFunction };
	}
	for (auto& t : threads) {
		t.join();
	}
}