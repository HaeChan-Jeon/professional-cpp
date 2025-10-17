#include <iostream>
#include <format>
#include <string>

using namespace std;

int main()
{
	string myString;
	getline(cin, myString, '@');
	cout << myString;

	char c;
	cin >> c;
	cout << format("Retrieved {} before putback('e').", c) << endl;
	cin.putback('e');
	cin >> c;
	cout << format("Retrieved {} after putback('e').", c) << endl;

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

	int sum{ 0 };

	while (!cin.bad()) {
		int number;
		cin >> number;
		if (cin.good()) {
			sum += number;
		} else if (cin.eof()) {
			break;
		} else if (cin.fail()) {
			cin.clear();
			string badToken;
			cin >> badToken;
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}
	cout << "The sum is " << sum << endl;
}

string readName(istream& stream)
{
	string name;
	char next;
	while (stream.get(next)) {
		name += next;
	}return name;
}

void getReservationData()
{
	string guestName;
	int partySize{ 0 };
	// 숫자가 나올 때까지 문자를 읽는다.
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	// 스트림이 에러 상태가 아니면 partSize 값을 읽는다.
	if (cin)
		cin >> partySize;

}