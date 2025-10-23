#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> intMap;

	if (auto result {intMap.insert({1, 4})}; result.second) {
		cout << "Insert succeeded!" << endl;
	}

	if (auto [iter, success] { intMap.insert({2, 5}) }; success) {
		cout << "Insert succeeded!" << endl;
	}

	auto ret = intMap.insert_or_assign(1, 5);
	if (ret.second) {
		cout << "Inserted." << endl;
	} else {
		cout << "Overwritten." << endl;
	}

	for (const auto& p : intMap ) {
		cout << p.second << endl;
	}
	
	auto it{ intMap.find(1) };
	if (it != end(intMap)) {
		it -> second = 100;
	}

	auto isKeyInMap{ intMap.contains(1) };

	map<int, int> intMap2;
	auto extractedNode{ intMap.extract(1) };
	intMap2.insert(move(extractedNode));

	intMap2.insert(intMap.extract(2));

	for (const auto& p : intMap) {
		cout << p.second << endl;
	}

	intMap.merge(intMap2);

	for (const auto& p : intMap) {
		cout << p.second << endl;
	}
}