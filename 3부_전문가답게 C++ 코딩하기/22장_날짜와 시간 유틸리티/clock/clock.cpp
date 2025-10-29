#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

int main()
{
	// 현재 시각을 time_point 타입으로 구한다.
	system_clock::time_point tpoint{ system_clock::now() };
	// time_t 값으로 변환한다.
	time_t tt{ system_clock::to_time_t(tpoint) };
	// 현재 시각으로 변환한다.
	tm t{};
	localtime_s(&t, &tt);
	// 최종 결과를 콘솔에 출력한다.
	cout << put_time(&t, "%H:%M:%S") << endl;

	// 사람이 읽기 좋은 포맷으로 변환한다.
	stringstream ss;
	ss << put_time(&t, "%H:%M:%S");
	string stringTime{ ss.str() };
	cout << stringTime << endl;

	// 또는 다음과 같이 작성한다.
	char buffer[80] = {0};
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &t);
	cout << buffer << endl;

	// 시작 시간을 구한다.
	auto start{ high_resolution_clock::now() };
	// 시간을 측정할 코드를 실행한다.
	double d{ 0 };
	for (int i{0}; i < 1'000'000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// 끝 시간을 구해서 시작 시간과의 차를 구한다.
	auto end{ high_resolution_clock::now() };
	auto diff{ end - start };
	cout << duration<double, milli> {diff}.count() << "ms" << endl;
}