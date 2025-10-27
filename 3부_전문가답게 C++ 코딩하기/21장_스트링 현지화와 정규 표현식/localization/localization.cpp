#include <iostream>
#include <format>
#include <locale>
#include <sstream>

using namespace std;

void print()
{
	stringstream stream;
	stream << 32767;
	cout << stream.str() << endl;
}

int main()
{
	print();
	locale::global(locale{ "en-US" });
	print();
}