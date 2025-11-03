module logger;

import <format>;

using namespace std;

void logSomeMessages(int id, Logger& logger)
{
	for (int i { 0 }; i  < 10; ++i) {
		logger.log(format("Log entry {} from thread {}", i, id));
	}
}

int main()
{
	Logger logger;
	vector<thread> threads;
	// 스레드 몇 개를 생성한다. 모두 동일한 logger 인스턴스를 다룬다.
	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back(logSomeMessages, i, ref(logger));
	}
	// 모든 스레드가 끝나길 기다린다.
	for (auto& t : threads ) {
		t.join();
	}
}