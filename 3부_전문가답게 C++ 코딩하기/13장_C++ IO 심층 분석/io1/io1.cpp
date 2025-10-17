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

	if (cout.good()) {
		cout << "All good\n" << endl;
	}

	cout.flush();
	if (cout.fail()) {
		cerr << "Unable to flush to standard out\n" << endl;
	}

	cout.flush();
	if (!cout) {
		cerr << "Unable to flush to standard out\n" << endl;
	}

	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	try	{
		cout << "Hello World." << endl;
	}
	catch (const ios_base::failure& ex) {
		cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}

	cout.clear();
}