#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class AccessList final
{
public:
    AccessList() = default;

    AccessList(std::initializer_list<std::string_view> users)
    {
        m_allowed.insert(begin(users), end(users));
    }

    void addUser(std::string user)
    {
        m_allowed.emplace(std::move(user));
    }

    void removeUser(const std::string& user)
    {
        m_allowed.erase(user);
    }

    bool isAllowed(const std::string& user) const
    {
        return (m_allowed.count(user) != 0);
    }
    
    std::vector<std::string> getAllUsers() const
    {
        return { begin(m_allowed), end(m_allowed) };
    }
private:
    std::set<std::string> m_allowed;
};

int main()
{
    AccessList fileX{ "mgregoire", "baduser" };
    fileX.addUser("pvw");
    fileX.removeUser("baduser");

    if (fileX.isAllowed("mgregoire")) {
        cout << "mgregoire has permissions" << endl;
    }

    if (fileX.isAllowed("baduser")) {
        cout << "baduser has permissions" << endl;
    }

    auto users{ fileX.getAllUsers() };
    for (const auto& user : users) {
        cout << user << " ";
    }
}