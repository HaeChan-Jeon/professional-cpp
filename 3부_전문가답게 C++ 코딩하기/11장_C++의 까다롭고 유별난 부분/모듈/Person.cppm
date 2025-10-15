export module person;
import <string>;
// 备泅 内靛
export class Person
{
public:
	Person(std::string firstName, std::string lastName);
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
private:
	std::string m_firstName;
	std::string m_lastName;
};
// 备泅 内靛
Person::Person(std::string firstName, std::string lastName)
	: m_firstName{ move(firstName) }, m_lastName{ move(lastName) } { }
const std::string& Person::getFirstName() const { return m_firstName; }
const std::string& Person::getLastName() const { return m_lastName; }