#include <iostream>
#include <format>
#include <locale>

using namespace std;

int main()
{
	wcout.imbue(locale{ "" });
	wcout << 32767 << endl;

	wcout.imbue(locale{ "C" });
	wcout << 32767 << endl;

	wcout.imbue(locale{ "en-US" });
	wcout << 32767 << endl;

	locale loc{ "" };
	if (loc.name().find("en_US") == string::npos &&
		loc.name().find("en-US") == string::npos) {
		wcout << L"Welcome non-US English speaker!" << endl;
	} else {
		wcout << L"Welcome US English speaker!" << endl;
	}
}