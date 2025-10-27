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
	sort(begin(values), end(values), greater<>{});

	// 선택 알고리즘
	nth_element(begin(values), begin(values) + 2, end(values), greater<>{});
	cout << "3rd largest valud: " << values[2] << endl;
	
	nth_element(begin(values), begin(values) + 4, end(values), greater<>{});
	sort(begin(values), begin(values) + 5);
	for_each_n(begin(values), 5, [](const auto& element) {cout << element << " "; });
}