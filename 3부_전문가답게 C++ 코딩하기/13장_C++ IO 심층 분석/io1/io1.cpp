#include <iostream>

using namespace std;

int main()
{
	const char* test{ "hello, there\n" };
	cout.write(test, strlen(test));

	cout.put('a');

	cout << "abc";
	cout.flush();
	cout << "def";
	cout << endl;
}