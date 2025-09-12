export module spreadsheet_cell;
import <string>;
import <string_view>;
export class SpreadsheetCell
{
	public:
		void setValue(double value);
		double getValue() const;

		void setString(std::string_view inString);
		std::string getString() const;
	private:
		std::string doubleToString(double value) const;
		double stringToDouble(std::string_view inString) const;
		double m_value{ 0 };
};