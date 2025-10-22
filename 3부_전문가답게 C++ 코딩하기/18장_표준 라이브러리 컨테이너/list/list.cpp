#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> dictionary{ "aardvark", "ambulance" };
    list<string> bWords{ "bathos", "balderdash" };
    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");

    if (!bWords.empty()) {
        auto iterLastB{ --(cend(bWords)) };
        auto it{ cbegin(dictionary) };
        for (; it != cend(dictionary); ++it) {
            if (*it > *iterLastB) {
                break;
            }
        }
        dictionary.splice(it, bWords);
    }

    for (const auto& word : dictionary) {
        cout << word << endl;
    }
}