import gird;

using namespace std;

using IntGrid = Grid<int>;
using DoubleGrid = Grid<double>;

int main()
{
	IntGrid myIntGrid;
	DoubleGrid myDoubleGrid{ 11, 11 };

	myIntGrid.at(0, 0) = 10;
	int x{ myIntGrid.at(0,1).value_or(0) };

	IntGrid grid2{ myIntGrid };
	IntGrid anotherIntGrid;
	anotherIntGrid = grid2;

	Grid<vector<int>> girdOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	girdOfVectors.at(5, 6) = myVector;
}