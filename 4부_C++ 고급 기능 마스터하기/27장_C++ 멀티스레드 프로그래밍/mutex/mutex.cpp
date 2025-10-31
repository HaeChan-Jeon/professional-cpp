#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <format>
#include <syncstream>
#include <chrono>

using namespace std;
using namespace chrono;

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id { id }, m_numIterations { numIterations } { }
	
	void operator()() const
	{
		for (int i { 0 }; i  < m_numIterations; ++i) {
			unique_lock lokc{ ms_timedMutex, 200ms };
			cout << "Counter" << m_id << " has value " << i << endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
	inline static timed_mutex ms_timedMutex;
};

int main()
{
}