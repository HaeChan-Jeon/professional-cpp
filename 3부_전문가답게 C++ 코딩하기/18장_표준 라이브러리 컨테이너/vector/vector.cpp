#include <vector>
#include <iostream>
#include <utility> // move
#include <string>

using namespace std;

int main()
{
	// 이동 의미론
	vector<string> vec;
	string myElement(5, 'a'); // "aaaaa"
	vec.push_back(move(myElement));

	vec.push_back(string(5, 'a'));
	// 또는
	vec.emplace_back(5, 'a');

	vector vec2{ 1, 2, 3 };
	cout << size(vec2) << endl;
	cout << empty(vec2) << endl;

	vector<int> values;
	// values 메모리 임시 벡터에 거주
	vector<int>().swap(values);

	// 데이터에 직접 접근하기
	vector vec3{ 1,2,3 };
	int* data1{ vec3.data() };
	int* data2{ data(vec3) };
}