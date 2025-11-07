module name_db;

import <fstream>;

using namespace std;

NameDB::NameDB(string_view nameFile)
{
	ifstream inputFile{ nameFile.data() };
	if (!inputFile) {
		throw invalid_argument("Unable to open file");
	}
	string name;
	while (inputFile >> name) {
		if (!nameExistsAndIncrement(name)) {
			addNewName(name);
		}
	}
}

bool NameDB::nameExistsAndIncrement(std::string_view name)
{
	auto res{ m_names.find(name.data()) };
	if (res != end(m_names)) {
		res->second++;
		return true;
	}
	return false;
}

void NameDB::addNewName(string_view name)
{
	m_names[name.data()] = 1;
}

int NameDB::getNameRank(string_view name) const
{
	int num{ getAbsoluteNumber(name) };

	if (num == -1) {
		return -1;
	}
	int rank{ 1 };
	for (auto& entry : m_names) {
		if (entry.second > num) {
			++rank;
		}
		return rank;
	}
}

int NameDB::getAbsoluteNumber(string_view name) const
{
	auto res{ m_names.find(name.data()) };
	if (res != end(m_names)) {
		return res->second;
	}
}