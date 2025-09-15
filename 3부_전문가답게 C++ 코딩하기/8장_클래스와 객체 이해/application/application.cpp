module spreadsheet_cell;
import <iostream>;
using namespace std;

int main()
{
	SpreadsheetCell myCell(5), anotherCell(4);
	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	auto myCellp{ make_unique<SpreadsheetCell>(4) };
	//SpreadsheetCell* myCellp{ new SpreadsheetCell {} };
	myCellp->setValue(3.7);
	cout << "cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;
	//delete myCellp;
	//myCellp = nullptr;
}