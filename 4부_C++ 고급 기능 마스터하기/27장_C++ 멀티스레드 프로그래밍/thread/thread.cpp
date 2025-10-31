#include <iostream>
#include <thread>

using namespace std;

class Counter
{
	public:
		Counter(int id, int numIterations)
			: m_id{ id }, m_numIterations{ numIterations } {
		}

		void operator()() const
		{
			for (int i{ 0 }; i < m_numIterations; ++i) {
				cout << "Counter " << m_id << " has value" << i << endl;
			}
		}
	private:
		int m_id;
		int m_numIterations;
};

int main()
{
	// 균일 초기화를 사용하는 방법
	thread t1{ Counter{1, 20} };

	// 일반 변수처럼 네임드 인스턴스로 초기화하는 방법
	Counter c{ 2, 12 };
	thread t2{ c };

	// 두 스레드가 모두 마칠 때까지 기다린다.
	t1.join();
	t2.join();
}