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
		if (nameExists(name)) {
			incrementNameCount(name);
		}
		else {
			addNewName(name);
		}
	}
}

bool NameDB::nameExists(string_view name) const
{
	for (auto& entry : m_names) {
		if (entry.first == name) {
			return true;
		}
	}
	return false;
}

void NameDB::incrementNameCount(string_view name)
{
	for (auto& entry : m_names) {
		if (entry.first == name) {
			++entry.second;
			return;
		}
	}
}

void NameDB::addNewName(string_view name)
{
	m_names.push_back(make_pair(name.data(), 1));
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
	for (auto& entry : m_names) {
		if (entry.first == name) {
			return entry.second;
		}
	}
	return -1;
}