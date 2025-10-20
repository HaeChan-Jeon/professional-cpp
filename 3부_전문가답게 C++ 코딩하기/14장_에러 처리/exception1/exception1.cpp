#include <source_location>
#include <string>
#include <format>
#include <iostream>

using namespace std;

class MyException : public exception
{
public:
	MyException(string_view message) : m_message { move(message)} {}
	const char* what() const noexcept override { return m_message.c_str(); }
private:
	string m_message;
};

void doSomeThing()
{
	try	{
		throw runtime_error{ "Throwing a runtime_error exception" };
	}
	catch (const runtime_error& e) {
		cout << format("{} caught a runtime_error", __func__) << endl;
		cout << format("{} throwing MyException", __func__) << endl;
		throw_with_nested(
			MyException{ "MyException with nested runtime_error" });
	};
}

int main()
{
	try {
		doSomeThing();
	} catch (const MyException& e) {
		cout << format("{} Caught MyException: {}", __func__, e.what()) << endl;
		try {
			rethrow_if_nested(e);
		} catch (const runtime_error& e) {
		cout << format(" Nested exception: {}", e.what()) << endl;
		}
	}
}