export module datamodel;	// damamodel ���(�⺻ ��� �������̽� ����)
export import :person;		// person ��Ƽ���� ����Ʈ�ϰ� �ͽ���Ʈ�Ѵ�.
export import :address;		// address ��Ƽ���� ����Ʈ�ϰ� �ͽ���Ʈ�Ѵ�.
import <vector>;
export namespace DataModel { using Persons = std::vector<Person>; }