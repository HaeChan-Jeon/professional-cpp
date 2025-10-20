#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include <source_location>

using namespace std;

int main()
{
	size_t integerCount{ numeric_limits<size_t>::max() };
	int* ptr{ new(nothrow) int[integerCount] };
	if (ptr == nullptr)	{
		auto location{ source_location::current() };
		cerr << format("{}({}): Unable to allocate memory!",
			location.file_name(), location.line()) << endl;
		return 0;
	}
}