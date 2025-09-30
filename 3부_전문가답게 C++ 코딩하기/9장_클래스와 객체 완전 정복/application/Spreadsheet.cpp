module;
#include <stdexcept>

module spreadsheet;
import <format>;
import <utility>;

using namespace std;

// 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
{
	swap(*this, src);
}

// 이동 대입 연산자
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	swap(*this, rhs);
	return *this;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	Spreadsheet temp{ rhs };	// 모든 작업을 임시 인스턴스에서 처리한다.
	swap(temp);					// 익셉션을 던지지 않는 연산에서만 작업을 처리한다.
	return *this;
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

void Spreadsheet::swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	first.swap(second);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet{ src.m_width, src.m_height }
{
	for (size_t i{ 0 }; i < m_width; i++)	{
		for (size_t j{ 0 }; j < m_height; j++) {
			m_cells[i][j] = src.m_cells[i][j];
		}
	}
}

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

const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<SpreadsheetCell&>(as_const(*this).getCellAt(x, y));
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

Spreadsheet::~Spreadsheet()
{
	for (size_t i{ 0 }; i < m_width; i++) {
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;
	m_width = m_height = 0;
}