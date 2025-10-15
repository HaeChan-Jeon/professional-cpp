export module person;	// 모듈 선언문

import <string>;

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