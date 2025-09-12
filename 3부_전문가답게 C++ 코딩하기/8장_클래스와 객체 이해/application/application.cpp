module spreadsheet_cell;
import <iostream>;
using namespace std;

int main()
{
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setString("3.2");
	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	auto myCellp{ make_unique<SpreadsheetCell>() };
	//SpreadsheetCell* myCellp{ new SpreadsheetCell {} };
	myCellp->setValue(3.7);
	cout << "cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;
	//delete myCellp;
	//myCellp = nullptr;
}