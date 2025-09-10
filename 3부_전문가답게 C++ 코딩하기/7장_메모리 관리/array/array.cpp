#include <iostream>

using namespace std;

// 객체 배열
class Simple
{
public:
	Simple() { cout << "Simple constructor caleld!" << endl; }
	~Simple() { cout << "Simple destructor caleld!" << endl; }
};

int main()
{
	int myArray[5];
	int myArray1[5]{ 1,2,3,4,5 };
	int myArray2[5]{ 1,2 };
	int myArray3[5]{ 0 };
	int myArray4[5]{ };
	int myArray5[]{ 1,2,3,4,5 };

	int* myArrayPtr1{ new int[5] {1, 2, 3, 4, 5} };

	delete[] myArrayPtr1;
	myArrayPtr1 = nullptr;

	Simple* mySimpleArray{ new Simple[4] };
	delete[] mySimpleArray;
	mySimpleArray = nullptr;

	const size_t size{ 4 };
	Simple** mySimplePtrArray{ new Simple* [size] };

	// 포인터마다 객체를 할당한다.
	for (size_t i{ 0 }; i< size; i++) { mySimplePtrArray[i] = new Simple(); }

	// mySimplePtrArray 사용

	// 할당된 객체를 삭제한다.
	for (size_t i{ 0 }; i < size; i++) {
		delete mySimplePtrArray[i];
		mySimplePtrArray[i] = nullptr;
	}

	// 배열을 삭제한다.
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	// 다차원 배열
	char board[3][3]{};
	// 테스트 코드
	board[0][0] = 'X';
	board[2][1] = 'O';
}

char** cllocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray{ new char* [xDimension] };
	for (size_t i{ 0 }; i < xDimension; ++i) {
		myArray[i] = new char[yDimension];
	}
	return myArray;
}

void releaseCharacterBoard(char** myArray, size_t xDimension)
{
	for (size_t i{ 0 }; i < xDimension; i++) {
		delete[] myArray[i];
		myArray[i] = nullptr;
	}
	delete[] myArray;
	myArray = nullptr;
}