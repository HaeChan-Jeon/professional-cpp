#include <vector>
#include <iostream>
#include <format>

using namespace std;

int main()
{
	vector<double> doubleVector;

	double max{ -numeric_limits<double>::infinity() };

	double temp;

	for (size_t i{ 1 }; true; i++) {
		cout << format("Enter score {}: (-1 to stop): ", i);
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		cout << element << " ";
	}
}