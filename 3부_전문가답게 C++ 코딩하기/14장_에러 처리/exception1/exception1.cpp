#include <source_location>
#include <string>
#include <format>
#include <iostream>

using namespace std;

void logMessage(string_view message,
	const source_location& location = source_location::current())
{
	cout << format("{}({}): {}: {}", location.file_name(),
		location.line(), location.function_name(), message) << endl;
}

void foo()
{
	logMessage("Starting execution of foo().");
}

int main()
{
	foo();
}