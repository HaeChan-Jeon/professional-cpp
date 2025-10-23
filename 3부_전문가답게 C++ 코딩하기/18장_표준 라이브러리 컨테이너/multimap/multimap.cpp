#include <iostream>
#include <map>
#include <vector>

using namespace std;

class BuddyList final
{
public:
    void addBuddy(const std::string& name, const std::string& buddy);
    void removeBuddy(const std::string& name, const std::string& buddy);
    bool isBuddy(const std::string& name, const std::string& buddy) const;
    std::vector<std::string> getBuddies(const std::string& name) const;
private:
    std::multimap<std::string, std::string> m_buddies;
};

void BuddyList::addBuddy(const string& name, const string& buddy)
{
    if (!isBuddy(name, buddy)) {
        m_buddies.insert({ name, buddy });
    }
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
    auto begin{ m_buddies.lower_bound(name) };
    auto end{ m_buddies.upper_bound(name) };

    for (auto iter {begin}; iter != end; ++iter) {
        if (iter->second == buddy) {
            m_buddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(const std::string& name, const std::string& buddy) const
{
    auto [begin, end] {m_buddies.equal_range(name)};

    for (auto iter{ begin }; iter != end; ++iter) {
        if (iter->second == buddy) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> BuddyList::getBuddies(const std::string& name) const
{
    auto [begin, end] {m_buddies.equal_range(name)};

    vector<string> buddies;
    for (auto iter{ begin }; iter != end; ++iter) {
        buddies.push_back(iter->second);
    }
    return buddies;
}

int main()
{
    BuddyList buddies;
    buddies.addBuddy("Harry Potter", "Ron Weasley");
    buddies.addBuddy("Harry Potter", "Hermione Granger");
    buddies.addBuddy("Harry Potter", "Hagrid");
    buddies.addBuddy("Harry Potter", "Draco Malfoy");

    buddies.removeBuddy("Harry Potter", "Draco Malfoy");

    buddies.addBuddy("Hagrid", "Harry Potter");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione Granger");

    auto harryFriends{ buddies.getBuddies("Harry Potter") };

    cout << "Harry's friends: " << endl;
    for (const auto& name : harryFriends) {
        cout << "\t" << name << endl;
    }
}