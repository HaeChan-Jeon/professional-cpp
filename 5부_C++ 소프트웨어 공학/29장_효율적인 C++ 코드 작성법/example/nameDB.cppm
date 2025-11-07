export module name_db;

import <string_view>;
import <vector>;
import <string>;

export class NameDB
{
public:
	NameDB(std::string_view nameFile);
	int getNameRank(std::string_view name) const;
	int getAbsoluteNumber(std::string_view name) const;
private:
	std::vector<std::pair<std::string, int>> m_names;

	bool nameExists(std::string_view name) const;
	void incrementNameCount(std::string_view name);
	void addNewName(std::string_view name);
};