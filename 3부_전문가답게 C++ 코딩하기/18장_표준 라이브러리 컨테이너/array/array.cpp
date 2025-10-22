#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 3> arr{ 9, 8, 7 };

	cout << "Array size = " << arr.size() << endl;

	for (const auto& i : arr) {
		cout << i << endl;
	}

	cout << "Performing arr.fil(3)..." << endl;

	arr.fill(3);

	for (auto iter { cbegin(arr) }; iter != cend(arr); ++iter) {
		cout << *iter << endl;
	}

	array<int, 3> myArray{ 11, 22, 33 };
	cout << std::get<1>(myArray) << endl;
	//cout << std::get<10>(myArray) << endl; // 컴파일 에러

	auto arr1{ to_array({11, 22, 33}) };

	double carry[]{ 9, 8, 7,6 };
	auto arr2{ to_array(carry) };
}