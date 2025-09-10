#include <array>;

void doubleInts(int* theArray, size_t size)
{
	for (size_t i{ 0 }; i < size; i++) { theArray[i] *= 2; }
}

int main()
{
	// 배열 = 포인터
	int myIntArray[10]{};
	int* myIntPtr{ myIntArray };
	//포인터로 배열 접근하기
	myIntPtr[4] = 5;

	size_t arrSize{ 4 };
	int* freeStoreArray{ new int[arrSize] {1, 5, 3, 4} };
	doubleInts(freeStoreArray, arrSize);
	delete[] freeStoreArray;
	freeStoreArray = nullptr;

	int stackArray[]{ 1, 2, 3, 4 };
	arrSize = std::size(stackArray);
	doubleInts(stackArray, arrSize);
	doubleInts(&stackArray[0], arrSize);
}
