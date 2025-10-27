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

template <typename Iterator>
void DumpRange(string_view message, Iterator begin, Iterator end)
{
	cout << message;
	for_each(begin, end, [](const auto& element) { cout << element << " "; });
	cout << endl;
}

int main()
{
	vector<int> vectorOne, vectorTwo, vectorMerged;
	cout << "Enter values for first vector:" << endl;
	polulateContainter(vectorOne);
	cout << "Enter values for second vector:" << endl;
	polulateContainter(vectorTwo);

	// 두 컨테이너를 정렬한다.
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// 두 원본 vector 합친 값을 모두 담을 정도로 대상 vector의 크기를 넉넉히 확보한다.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne),
		cbegin(vectorTwo), cend(vectorTwo), begin(vectorMerged));

	DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));
}