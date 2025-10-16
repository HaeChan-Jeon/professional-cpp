import grid;

import <iostream>;

using namespace std;

int main()
{
	//size_t height{ 10 };
	//Grid<int, 10, height> testGrid; // 컴파일 에러 발생

	const size_t height{ 10 };
	Grid<int, 10, height> testGrid; // 컴파일 성공

	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;
	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;
	cout << anotherGrid.at(2, 3).value_or(0);
}