module spreadsheet_cell;
import <charconv>;
import <iostream>;
using namespace std;

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	m_value = rhs.m_value;
	return *this;
}

SpreadsheetCell::~SpreadsheetCell()
{
	//cout << "Destructor called." << endl;
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: m_value { initialValue }
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
{
	set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
	: m_value { src.m_value }
{
}

void SpreadsheetCell::set(double value)
{
	m_value = value;
}

double SpreadsheetCell::getValue() const
{
	m_numAccesses++;
	return m_value;
}

void SpreadsheetCell::set(string_view value)
{
	m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
	m_numAccesses++;
	return doubleToString(m_value);
}

string SpreadsheetCell::doubleToString(double value)
{
	return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value)
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}