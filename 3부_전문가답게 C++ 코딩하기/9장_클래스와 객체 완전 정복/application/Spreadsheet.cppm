module;
#include <cstddef>

export module spreadsheet;
export import spreadsheet_cell;

export class Spreadsheet
{
	public:
		Spreadsheet(const Spreadsheet& src);
		Spreadsheet(size_t width, size_t height);
		~Spreadsheet();
		void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
		SpreadsheetCell& getCellAt(size_t x, size_t y);
		void verifyCoordinate(size_t x, size_t y) const;
	private:
		bool inRange(size_t value, size_t upper) const;
		size_t m_width{ 0 };
		size_t m_height{ 0 };
		SpreadsheetCell** m_cells{ nullptr };
};