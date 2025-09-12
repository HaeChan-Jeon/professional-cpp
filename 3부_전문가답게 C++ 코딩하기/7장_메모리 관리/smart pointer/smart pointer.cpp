#include <memory>
#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { m_intPtr = new int{}; }
	~Simple() { delete m_intPtr; }
	void setValue(int value) { *m_intPtr = value; }
	//void go();
private:
	int* m_intPtr;
};

// unique_ptr 생성 방법
void leaky()
{
	Simple* mySimplePtr{ new Simple() }; // 버그!메모리를 해제하지 않았다.
	//mySimplePtr->go();
}

void couldBeLeaky()
{
	Simple* mySimplePtr{ new Simple() };
	//mySimplePtr->go();
	delete mySimplePtr;
 }

void notLeaky()
{
	unique_ptr<Simple> mySimpleSmartPtr1{ make_unique<Simple>() };
	//mySimpleSmartPtr1->go();

	unique_ptr<Simple> mySimpleSmartPtr2{ new Simple{} };
	//mySimpleSmartPtr2->go();

	// unique_ptr 사용 방법
	//(*mySimpleSmartPtr1).go();

	//processData(mySimpleSmartPtr1.get());

	mySimpleSmartPtr1.reset();				// 리소스 해제 후 nullptr로 초기화
	mySimpleSmartPtr1.reset(new Simple());	// 리소스 해제 후 새로운 Simple 인스턴스로 설정

	Simple* simple{ mySimpleSmartPtr1.release() };	// 소유권을 해제한다.
	// simple 포인터를 사용하는 코드
	//simple->go();
	delete simple;
	simple = nullptr;
}

// void processData(Simple* simple)
//{
//	// 스마트 포인터를 사용하는 코드
//}

// unique_ptr과 c 스타일 배열
auto myVariableSizedArray{ make_unique<int[]>(10) };

// 커스텀 제거자
int* my_alloc(int value) { return new int{ value }; }
void my_free(int* p) { delete p; }

auto mySimpleSmartPtr1{ make_shared<Simple>() };

shared_ptr<int> myIntSmartPtr{ my_alloc(42), my_free };

class Foo : public enable_shared_from_this<Foo>
{
public:
	Foo(int value) : m_data(value) {}
	int m_data;

	shared_ptr<Foo> getPointer() {
		return shared_from_this();
	}
};

void useResource(weak_ptr<Simple>& weakSimple)
{
	auto resource{ weakSimple.lock() };
	if (resource) {
		cout << "Resource still alive." << endl;
	}
	else {
		cout << "Resource has bee freed!" << endl;
	}
}

unique_ptr<Simple> create()
{
	auto fooPtr1{ make_shared<Foo>()};
	auto fooPtr2{ fooPtr1->getPointer() };

	auto ptr{ make_unique<Simple>() };
	return ptr;
}

int main()
{
	unique_ptr<Simple> mySmartPtr10{ create() };
	auto mySmartPtr11{ create() };

	auto SharedSimple{ make_shared<Simple>() };
	weak_ptr<Simple> weakSimple{ SharedSimple };

	// weak_ptr을 사용한다.
	useResource(weakSimple);

	// shared_ptr을 리셋한다.
	// Simple 리소스에 대한 shared_ptr은 하나뿐이므로
	// weak_ptr이 살아 있더라도 리소스가 해제된다.
	SharedSimple.reset();

	// weark_ptr을 한 번 더 사용한다.
	useResource(weakSimple);

	myVariableSizedArray[1] = 123;

	Simple* mySimple1{ new Simple() };
	Simple* mySimple2{ mySimple1 };

	delete mySimple2;
	delete mySimple1;

	auto smartPtr1{ make_shared<Simple>() };
	auto smartPtr2{ smartPtr1 };

	Simple* mySimple4{ new Simple() };
	shared_ptr<Simple> smartPtr5{ mySimple4 };
	shared_ptr<Simple> smartPtr6{ mySimple4 };

	auto foo{ make_shared<Foo>(42) };
	auto aliasing{ shared_ptr<int> {foo, &foo->m_data} };
}