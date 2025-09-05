#include <iostream>
#include <string>
#include <format>
#include <charconv>

using namespace std;

int main()
{
	long double d{ 3.14L };
	string s{ to_string(d) };
	cout << d << endl;
	cout << s << endl << endl;

	const string toParse{ "123USD" };
	size_t index{ 0 };
	cout << index << endl;
	int value{ stoi(toParse, &index) };
	cout << "Parsed value: " << value << endl;
	cout << "First non-parsed character: " << toParse[index] << endl;
	cout << index << endl;
	cout << toParse << endl;

	// 로우 레벨 숫자 변환
	const size_t BufferSize{ 50 };
	string out(BufferSize, ' ');

	auto result{ to_chars(out.data(), out.data() + out.size(), 12345) };
	if (result.ec == errc{}) { cout << out << endl; }

	string out2(BufferSize, ' ');
	auto [ptr, error] { to_chars(out2.data(), out2.data() + out2.size(), 12345) };
	if (error == errc{}) { cout << out2 << endl; }

	double value2{ 0.314 };
	string out3(BufferSize, ' ');
	auto [ptr2, error2] {to_chars(out3.data(), out3.data() + out3.size(), value2)};
	if (error2 == errc{}) { cout << out3 << endl; }

	// 스트링을 숫자로 변환
	double value5{ 0.314 };
	string out5(BufferSize, ' ');
	auto [ptr5, error5] {to_chars(out5.data(), out5.data() + out5.size(), value5)};
	if (error5 == errc{}) { cout << out5 << endl; }

	double value6;
	auto [ptr6, error6] {from_chars(out5.data(), out5.data() + out5.size(), value6)};
	if (value5 == value6) {
		cout << "Perfect roundtrip" << endl;
	} else {
		cout << "No perfect roundtrip?!?" << endl;
	}
}