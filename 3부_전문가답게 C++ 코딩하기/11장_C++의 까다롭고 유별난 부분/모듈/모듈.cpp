import person;
import <iostream>;
import <string>;

using namespace std;

int main()
{
	Person person{ "Haechan", "Jeon" };
	cout << person.getLastName() << ", " << person.getFirstName() << endl;
}