export module datamodel;	// damamodel 모듈(기본 모듈 인터페이스 파일)
export import :person;		// person 파티션을 임포트하고 익스포트한다.
export import :address;		// address 파티션을 임포트하고 익스포트한다.
import <vector>;
export namespace DataModel { using Persons = std::vector<Person>; }