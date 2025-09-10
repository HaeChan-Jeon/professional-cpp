#include <iostream>

using namespace std;

int main()
{
	// 메모리의 작동 과정 살펴보기
	int i{ 7 }; // 자동 변수, 스택

	//int* ptr{ nullptr };
	//ptr = new int; // 프리스토어 할당

	int* ptr { new int };

	// 포인트가 스택과 프리스토어에 모두 있는 예
	int** handle{ nullptr };
	handle = new int*;
	*handle = new int;

	// 메모리 할당과 해제
	// malloc()

}

void leaky()
{
	//new int;
	//cout << "방금 int 하나를 잃어버렸다." << endl;

	//int* ptr{ new int };
	//delete ptr;
	//ptr = nullptr;

	int* ptr{ new(nothrow) int }; //바람직하지 않음
}