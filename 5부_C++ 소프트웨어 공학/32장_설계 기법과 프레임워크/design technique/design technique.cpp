#include <stdexcept>
#include <iostream>

using namespace std;

void throwIf(bool throwIt)
{
	if (throwIt) {
		throw runtime_error{ "Here's my exception" };
	}
}

int main()
{
	try {
		throwIf(false);
		throwIf(true);
	}
	catch (const runtime_error& e) {
		cerr << "Caught exception: " << e.what() << endl;
		return 1;
	}
}