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
}


int main()
{
}