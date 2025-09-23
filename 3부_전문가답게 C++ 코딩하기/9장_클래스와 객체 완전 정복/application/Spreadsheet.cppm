module;
#include <cstddef>

export module spreadsheet;
export import spreadsheet_cell;

export class Spreadsheet
{
	public:
		Spreadsheet(Spreadsheet&& src) noexcept; // 이동 생성자
		Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자
		Spreadsheet(size_t width, size_t height);
		Spreadsheet(const Spreadsheet& src);
		~Spreadsheet();
		Spreadsheet& operator=(const Spreadsheet& rhs) = delete;
		void swap(Spreadsheet& other) noexcept;
		void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
		SpreadsheetCell& getCellAt(size_t x, size_t y);
		void verifyCoordinate(size_t x, size_t y) const;
	private:
		void cleanup() noexcept;
		void moveFrom(Spreadsheet& src) noexcept;
		bool inRange(size_t value, size_t upper) const;
		size_t m_width{ 0 };
		size_t m_height{ 0 };
		SpreadsheetCell** m_cells{ nullptr };
};
export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;