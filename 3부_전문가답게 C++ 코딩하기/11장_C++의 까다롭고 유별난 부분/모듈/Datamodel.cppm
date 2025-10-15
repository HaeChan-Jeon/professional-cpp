export module datamodel;
export import datamodel.person;
export import datamodel.address;
import <vector>;
export namespace DataModel { using Persons = std::vector<Person>; }