module;
#include <stdexcept>

module spreadsheet;
import <format>;

using namespace std;


Spreadsheet::Spreadsheet(size_t width, size_t height)
	: m_width { width }, m_height {height}
{
	m_cells = new SpreadsheetCell * [m_width];
	for (size_t i{ 0 }; i < m_width; i++) {
		m_cells[i] = new SpreadsheetCell[m_height];
	}
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width)
	{
		throw out_of_range{ format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height)
	{
		throw out_of_range{ format("{} must be less than {}.", y, m_height) };
	}
}
