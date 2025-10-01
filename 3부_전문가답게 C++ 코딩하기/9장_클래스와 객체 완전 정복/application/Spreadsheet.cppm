module;
#include <cstddef>

export module spreadsheet;
export import spreadsheet_cell;

export class SpreadsheetApplication{};

export class Spreadsheet
{
	public:
		Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자
		Spreadsheet(size_t width, size_t height,
			const SpreadsheetApplication& theApp);
		Spreadsheet(const Spreadsheet& src);
		~Spreadsheet();
		Spreadsheet& operator=(const Spreadsheet& rhs);
		void swap(Spreadsheet& other) noexcept;
		void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
		void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
		SpreadsheetCell& getCellAt(size_t x, size_t y);
		const SpreadsheetCell& getCellAt(size_t x, size_t y) const;
		void verifyCoordinate(size_t x, size_t y) const;
		static const size_t MaxHeight{ 100 };
		static const size_t MaxWidth{ 100 };
	private:
		size_t m_width{ 0 };
		size_t m_height{ 0 };
		SpreadsheetCell** m_cells{ nullptr };
		static inline size_t ms_counter{ 0 };
		const size_t m_id{ 0 };
		const SpreadsheetApplication& m_theApp;
};