#include <iostream>
#include <unordered_map>
#include <format>

using namespace std;

void printMap(const auto& m)
{
	for (auto& [key, value] : m) {
		cout << format("{} (phone: {})", key, value) << endl;
	}
	cout << "----------" << endl;
}

int main()
{
	unordered_map<string, string> phoneBook{
		{"Marc G.", "123-456678"},
		{"Scott K.", "654-987321"} };
	printMap(phoneBook);

	phoneBook.insert(make_pair("John D.", "321-987654"));
	phoneBook["Johan G."] = "963-258147";
	phoneBook["Freddy K."] = "999-256256";
	phoneBook.erase("Freddy K.");
	printMap(phoneBook);

	const size_t bucket{ phoneBook.bucket("Marc G.") };
	cout << format("Marc G. is in bucket {} containing the following {} names:",
		bucket, phoneBook.bucket_size(bucket)) << endl;

	auto localBegin{ phoneBook.cbegin(bucket) };
	auto localEnd{ phoneBook.cend(bucket) };
	for (auto iter{localBegin}; iter != localEnd; ++iter) {
		cout << format("\t{} (phone: {})", iter->first, iter->second) << endl;
	}
	cout << "----------" << endl;

	cout << format("There are {} bucket.", phoneBook.bucket_count()) << endl;
	cout << format("Average number of elements in a bucket is {}",
		phoneBook.load_factor()) << endl;
}