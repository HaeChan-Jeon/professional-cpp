#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Container>
void polulateContainter(Container& cont)
{
	while (true) {
		cout << "Enter a number (0 to quit): ";
		int value;
		cin >> value;
		if (value == 0) { break; }
		cont.push_back(value);
	}
}

int main()
{
	vector<int> values;
	polulateContainter(values);

	sort(begin(values), end(values));

	//cout << "Sorted vector: ";
	//for (const auto& i : values) { cout << i << " "; }
	//cout << endl;

	//while (true) {
	//	int number;
	//	cout << "Enter a number to insert (0 th quit): ";
	//	cin >> number;
	//	if (number == 0) { break; }

	//	auto iter{ lower_bound(begin(values), end(values), number) };
	//	values.insert(iter, number);

	//	cout << "New vector: ";
	//	for (const auto& i : values) { cout << i << " "; }
	//	cout << endl;
	//}

	while (true) {
		int number;
		cout << "Enter a number to insert (0 th quit): ";
		cin >> number;
		if (number == 0) { break; }

		if (binary_search(cbegin(values), cend(values), number)) {
			cout << "That number is in the vector." << endl;
		} else {
			cout << "That number is not in the vector." << endl;
		}
	}
}