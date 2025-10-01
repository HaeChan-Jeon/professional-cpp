module;
#include <cstddef>

export module spreadsheet;
export import spreadsheet_cell;

export class Spreadsheet
{
	public:
		Spreadsheet(Spreadsheet&& src) noexcept; // 이동 생성자
		Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자
		Spreadsheet(size_t width = 100, size_t height = 100);
		Spreadsheet(const Spreadsheet& src);
		~Spreadsheet();
		Spreadsheet& operator=(const Spreadsheet& rhs);
		void swap(Spreadsheet& other) noexcept;
		void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
		void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
		SpreadsheetCell& getCellAt(size_t x, size_t y);
		const SpreadsheetCell& getCellAt(size_t x, size_t y) const;
		void verifyCoordinate(size_t x, size_t y) const;
	private:
		bool inRange(size_t value, size_t upper) const;
		size_t m_width{ 0 };
		size_t m_height{ 0 };
		SpreadsheetCell** m_cells{ nullptr };
};
export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;