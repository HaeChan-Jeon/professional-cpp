#include <iostream>

using namespace std;

class Person
{
    public:
        Person() = default;
        Person(string firstName, string lastName, int age)
            : m_firstName{ move(firstName) }, m_lastName{ move(lastName) }
            , m_age { age } { }
        virtual ~Person() = default;

        const string& getFirstName() const { return m_firstName; }
        const string& getLastName() const { return m_lastName; }
        int getAge() const { return m_age; }
    private:
        string m_firstName, m_lastName;
        int m_age{ 0 };
};

//void processPerson(Person& p) {/* Person 타입 객체를 처리한다. */ }
void processPerson(const Person& p) {/* Person 타입 객체를 처리한다. */}

int main()
{
    Person me{ "Marc", "Gregoire", 42 };
    processPerson(me);
}