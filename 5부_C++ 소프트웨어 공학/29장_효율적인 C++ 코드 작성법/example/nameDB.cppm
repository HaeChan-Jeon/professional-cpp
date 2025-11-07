export module name_db;

import <string_view>;
import <map>;
import <string>;

export class NameDB
{
public:
	NameDB(std::string_view nameFile);
	int getNameRank(std::string_view name) const;
	int getAbsoluteNumber(std::string_view name) const;
private:
	std::map<std::string, int> m_names;
};