#include <iostream>
#include <string_view>
#include <format>

using namespace std;

string_view extractExtension(string_view filename)
{
	return filename.substr(filename.rfind('.'));
}

int main()
{
	string filename{ R"(c;\temp\my file.ext)" };
	cout << format("C++ string: {}", extractExtension(filename)) << endl;

	const char* cString{ R"(c;\temp\my file.ext)" };
	cout << format("C string: {}", extractExtension(cString)) << endl;

	cout << format("Literal: {}", extractExtension(R"(c;\temp\my file.ext)")) << endl;

	// std::string_view와 임시 스트링
	string s{ "Hello" };
	string_view sv{ s + " World!" };
	cout << sv << endl;

	// std::string_view 리터럴
	auto sv2{ "My string_view"sv };

	// 포맷 지정자
	int i{ 42 };
	cout << format("|{:5}|", i) << endl;
	cout << format("|{:{}}|", i, 7) << endl;
	cout << format("|{:7}|", i) << endl;
	cout << format("|{:<7}|", i) << endl;
	cout << format("|{:_>7}|", i) << endl;
	cout << format("|{:_^7}|", i) << endl;

	cout << format("|{:<5}|", i) << endl;
	cout << format("|{:<+5}|", i) << endl;
	cout << format("|{:< 5}|", i) << endl;
	cout << format("|{:< 5}|", -i) << endl;
}