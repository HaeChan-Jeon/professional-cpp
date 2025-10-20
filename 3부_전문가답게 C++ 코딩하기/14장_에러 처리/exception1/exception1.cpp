#include <string>
#include <iostream>
#include <fstream>
#include <format>
#include <source_location>

using namespace std;

int main()
{
	int* ptr{ nullptr };
	size_t integerCount{ numeric_limits<size_t>::max() };
	cout << format("Trying to allocate memory for {} integers.", integerCount) << endl;
	try {
		ptr = new int[integerCount];
	} catch (const bad_alloc& e) {
		auto location{ source_location::current() };
		cerr << format("{}({}): Unable to allocate memory: {}",
			location.file_name(), location.line(), e.what()) << endl;
		return 0;
	}
}