#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <format>
#include <syncstream>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id { id }, m_numIterations { numIterations } { }
	
	void operator()() const
	{
		for (int i { 0 }; i  < m_numIterations; ++i) {
		/*	osyncstream { cout } << "Counter"
				<< m_id << " has value " << i << endl;*/
			
			osyncstream syncedCout{ cout };
			syncedCout << m_id << " has value " << i << endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
};

int main()
{
}