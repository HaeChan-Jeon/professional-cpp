export module logger;

import <queue>;
import <mutex>;
import <thread>;
import <fstream>;

export class Logger
{
	public:
		// 로그 항목을 파일에 저장하는 백그라운드 스레드를 구동한다.
		Logger();
		// 백그라운드 스레드를 정상적으로 종료시킨다.
		virtual ~Logger();
		// 복제 생성자와 대입 연산자를 삭제한다.
		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& rhs) = delete;
		// 로그 항목을 큐에 저장하는 함수
		void log(std::string entry);
	private:
		// 백그라운드 스레드에서 실행할 함수
		void processEntries();
		// 큐를 처리하는 헬퍼 메서드
		void processEntriesHelper(std::queue<std::string>& queue,
			std::ofstream& ofs) const;
		// 큐 동기화에 사용할 뮤텍스와 상태 변수
		std::mutex m_mutex;
		std::condition_variable m_condVar;
		std::queue<std::string> m_queue;
		// 백그라운드 스레드
		std::thread m_thread;
		// 백그라운드 스레드의 종료 여부를 표시하는 부울 변수
		bool m_exit{ false };
};