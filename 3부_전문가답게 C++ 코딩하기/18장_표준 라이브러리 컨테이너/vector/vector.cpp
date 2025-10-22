#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<double> doubleVector(10);
	double max = 0;

	//for (vector<double>::iterator iter{ begin(doubleVector) };
	//	iter != end(doubleVector); ++iter) {
	//		*iter /= max;
	//		cout << *iter << "";
	//	}

	for (auto iter{ begin(doubleVector) };
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << "";
	}

	//vector<string> stringVector(10, "hello");
	//for (auto it{ begin(stringVector) }; it != end(stringVector); ++it) {
	//	it->append(" there");
	//}

	vector<string> stringVector(10, "hello");
	for (auto& str : stringVector) {
		str.append(" there");
	}

	for (auto iter{ cbegin(stringVector)}; iter != cend(stringVector); ++iter) {
		cout << *iter << endl;
	}

	for (const auto& element : stringVector) {
		cout << element << endl;
	}
}