export module spreadsheet_cell;
import <string>;
import <string_view>;
export class SpreadsheetCell
{
	public:
		SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

		~SpreadsheetCell();
		
		SpreadsheetCell() = default;
		SpreadsheetCell(double initialValue);
		SpreadsheetCell(std::string_view initialValue);
		SpreadsheetCell(const SpreadsheetCell& src);
		void set(double value);
		void set(int) = delete;
		double getValue() const;

		void set(std::string_view inString);
		std::string getString() const;

		[[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;
	private:
		static std::string doubleToString(double value);
		static double stringToDouble(std::string_view inString);
		double m_value{ 0 };
		mutable size_t m_numAccesses{ 0 };
};