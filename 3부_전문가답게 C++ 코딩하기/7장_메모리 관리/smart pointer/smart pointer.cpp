#include <memory>

using namespace std;

class Simple
{
public:
	Simple() { m_intPtr = new int{}; }
	~Simple() { delete m_intPtr; }
	void setValue(int value) { *m_intPtr = value; }
	void go();
private:
	int* m_intPtr;
};

// unique_ptr 생성 방법
void leaky()
{
	Simple* mySimplePtr{ new Simple() }; // 버그!메모리를 해제하지 않았다.
	mySimplePtr->go();
}

void couldBeLeaky()
{
	Simple* mySimplePtr{ new Simple() };
	mySimplePtr->go();
	delete mySimplePtr;
 }

void notLeaky()
{
	unique_ptr<Simple> mySimpleSmartPtr1{ make_unique<Simple>() };
	mySimpleSmartPtr1->go();

	unique_ptr<Simple> mySimpleSmartPtr2{ new Simple{} };
	mySimpleSmartPtr2->go();

	// unique_ptr 사용 방법
	(*mySimpleSmartPtr1).go();

	processData(mySimpleSmartPtr1.get());

	mySimpleSmartPtr1.reset();				// 리소스 해제 후 nullptr로 초기화
	mySimpleSmartPtr1.reset(new Simple());	// 리소스 해제 후 새로운 Simple 인스턴스로 설정

	Simple* simple{ mySimpleSmartPtr1.release() };	// 소유권을 해제한다.
	// simple 포인터를 사용하는 코드
	simple->go();
	delete simple;
	simple = nullptr;
}

void processData(Simple* simple)
{
	// 스마트 포인터를 사용하는 코드
}

// unique_ptr과 c 스타일 배열
auto myVariableSizedArray{ make_unique<int[]>(10) };

// 커스텀 제거자
int* my_alloc(int value) { return new int{ value }; }

int main()
{
	myVariableSizedArray[1] = 123;
}