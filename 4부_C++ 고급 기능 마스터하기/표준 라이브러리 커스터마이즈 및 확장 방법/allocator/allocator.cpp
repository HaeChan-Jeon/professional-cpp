#include <scoped_allocator>

using namespace std;

class MyClass {};
int main()
{
	// 사용할 할당자를 생성한다.
	allocator<MyClass> alloc;
	// MyClass 인스턴스 한 개에 대한 초기화되지 않은 메모리 블록을 할당한다.
	auto* memory{ alloc.allocate(1) };
	// new 연산자를 이용하여 방금 생성한 블록에 MyClass 객체를 생성한다.
	new(memory) MyClass;
	// MyClass 인스턴스를 제거한다.
	destroy_at(memory);
	// 메모리 블록을 해제한다.
	alloc.deallocate(memory, 1);
	memory = nullptr;
}