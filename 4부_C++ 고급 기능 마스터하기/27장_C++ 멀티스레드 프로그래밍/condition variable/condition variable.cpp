#include <iostream>
#include <condition_variable>
#include <queue>

using namespace std;

queue<string> m_queue;
mutex m_mutex;
condition_variable m_condVar;

int main()
{
	// 뮤텍스에 락을 걸고 큐에 원소를 추가한다.
	unique_lock lock{ m_mutex };
	string entry{};
	m_queue.push(entry);
	// 스레드를 깨우도록 알림을 보낸다.
	m_condVar.notify_all();
}

bool doSomething()
{
	unique_lock lock{ m_mutex };

	while (true) {
		// 알림을 기다린다.
		m_condVar.wait(lock, [this] { return !m_queue.empty();});
		// 상태 변술를 통한 알림이 도착했ㄷ. 따라서 큐에 뭔가 추가되었다는 것을 알 수 있다.
		// 추가된 항목을 처리한다.
	}
}