module;					// 글로벌 모듈 프래그먼트 시작
#include <cstddef>		// 레거시 헤더 파일 추가

export module person;	// 명명 모듈 선언문

import <string>;

export class Person
{
public:
	Person(std::string firstName, std::string lastName)
		: m_firstName { std::move(firstName)}
		, m_lastName {std::move(lastName)} { }
	const std::string& getFirstName() const { return m_firstName; }
	const std::string& getLastName() const { return m_lastName; }
private:
	std::string m_firstName;
	std::string m_lastName;
};