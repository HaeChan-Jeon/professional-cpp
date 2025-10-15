module person;	// 모듈 선언문, 이때 export 키워드는 생략한다.

using namespace std;

Person::Person(string firstName, string lastName)
	: m_firstName { move(firstName) }, m_lastName { move(lastName) }
{
}

const string& Person::getFirstName() const { return m_firstName; }
const string& Person::getLastName() const { return m_lastName; }