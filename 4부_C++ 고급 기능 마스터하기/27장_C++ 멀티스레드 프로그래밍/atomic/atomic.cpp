#include <atomic>
#include <iostream>

using namespace std;

class Foo { private: int m_array[123]; };
class Bar { private: int m_int; };

int main()
{
	atomic<Foo> f;
	// 결과: 1 0
	cout << is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << endl;

	atomic<Bar> b;
	// 결과: 1 1
	cout << is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << endl;
}