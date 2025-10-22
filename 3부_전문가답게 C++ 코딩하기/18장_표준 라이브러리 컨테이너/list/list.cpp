#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<string> getTotalEnrollment(const vector<list<string>>& courseStudent,
	const list<string>& droppedStudents)
{
	list<string> allStudents;
		
		for (auto& lst : courseStudent) {
			allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
		}

		allStudents.sort();
		allStudents.unique();

		for (auto& str : droppedStudents) {
			allStudents.remove(str);
		}

		return allStudents;
}

int main()
{
}