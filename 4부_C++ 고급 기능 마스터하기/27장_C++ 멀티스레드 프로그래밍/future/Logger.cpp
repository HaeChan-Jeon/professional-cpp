module logger;

import <iostream>;
import <chrono>;

using namespace std;

Logger::Logger()
{
	m_thread = thread{ &Logger::processEntries, this };
}

Logger::~Logger()
{
	{
		unique_lock lock{ m_mutex };
		// m_exit를 true로 설정하고 스레드에 알림을 보내서 스레드를 정상 종료시킨다.
		m_exit = true;
	}
	// 스레드를 깨우도록 상태 변수에 알림을 보낸다.
	m_condVar.notify_one();
	// 스레드가 종료될 때까지 기다린다. 이 부분은 앞에 나온 블록 밖에 둬야 한다.
	// join()을 호출하기 전에 반드시 락을 해제해야 하기 때문이다.
	m_thread.join();
}

void Logger::log(string entry)
{
	// 뮤텍스에 락을 걸고 큐에 항목을 추가한다.
	unique_lock lock{ m_mutex };
	m_queue.push(move(entry));
	// 상태 변수에 알림을 보내서 스레드를 깨운다.
	m_condVar.notify_all();
}

void Logger::processEntries()
{
	// 로그 파일을 연다.
	ofstream logFile{ "log.txt" };
	if (logFile.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// m_mutex에 대한 락을 생성한다. 아직 이에 대한 락을 얻지 않는다.
	unique_lock lock{ m_mutex, defer_lock };
	// 큐를 처리하는 루프를 처리한다.
	while (true) {
		lock.lock();

		if (!m_exit) {
			this_thread::sleep_for(1000ms);
			m_condVar.wait(lock);
		}
		else
		{
			processEntriesHelper(m_queue, logFile);
			break;
		}
		// 상태 변수로 알림이 왔으며, 큐에 뭔가 들어 있다.

		// 락을 갖고 있는 동안 현재 큐의 내용을 스택의 빈 로컬 큐와 맞바꾼다.
		queue<string> localQueue;
		localQueue.swap(m_queue);

		// 현재 큐에 로컬 큐로 모든 항목을 옮겼다면
		// 락을 반납하고 다른 스레드를 해제시키고, 항목들에 대한 처리 작업을 수행한다.
		lock.unlock();

		// 스택에 있는 로컬 큐의 항목을 처맇나다.
		// 락을 해제한 후에 진행하므로, 다른 스레드가 블록되지 않는다.
		processEntriesHelper(localQueue, logFile);
	}
}

void Logger::processEntriesHelper(queue<string>& queue, ofstream& ofs) const
{
	while (!queue.empty()) {
		ofs << queue.front() << endl;
		queue.pop();
	}
}