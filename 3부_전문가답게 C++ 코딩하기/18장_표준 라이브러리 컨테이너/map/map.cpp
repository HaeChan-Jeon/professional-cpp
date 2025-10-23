#include <iostream>
#include <map>

using namespace std;

class BankAccount final
{
public:
	BankAccount(int accountNumber, std::string name)
		: m_accountNumber { accountNumber }, m_clientName { std::move(name)} { }
	void setaccountNumber(int accountNumber) {
		m_accountNumber = accountNumber; }
	int getaccountNumber() const { return m_accountNumber; }

	void setClientName(std::string name) { m_clientName = std::move(name); }
	const std::string& getClientName() const { return m_clientName; }
private:
	int m_accountNumber;
	std::string m_clientName;
};

class BankDB final
{
public:
	bool addAccount(const BankAccount& account);

	void deleteAccount(int accountNumber);

	BankAccount& findAccount(int accountNumber);
	BankAccount& findAccount(std::string_view name);

	void mergeDatabase(BankDB& db);
private:
	std::map<int, BankAccount> m_accounts;
};

bool BankDB::addAccount(const BankAccount& account)
{
	auto res{ m_accounts.emplace(account.getaccountNumber(), account) };

	return res.second;
}

void BankDB::deleteAccount(int accountNumber)
{
	m_accounts.erase(accountNumber);
}

BankAccount& BankDB::findAccount(int accountNumber)
{
	auto it{ m_accounts.find(accountNumber) };
	if (it == end(m_accounts)){
		throw std::out_of_range{ "No account with that number." };
	}
	
	return it->second;
}

BankAccount& BankDB::findAccount(string_view name)
{
	for (auto& [accountNumber, account] : m_accounts) {
		if (account.getClientName() == name) {
			return account;
		}
	}
	throw std::out_of_range{ "No account with that name." };
}

void BankDB::mergeDatabase(BankDB& db)
{
	m_accounts.merge(db.m_accounts);
	db.m_accounts.clear();
}

int main()
{
	BankDB db;
	db.addAccount(BankAccount{ 100, "Nicholas Solter" });
	db.addAccount(BankAccount{ 200, "Scott Kleper" });

	try {
		auto& account{ db.findAccount(100) };
		cout << "Found account 100" << endl;
		account.setClientName("Nicholas A Solter");

		auto& account2{ db.findAccount("Scott Kleper")};
		cout << "Found account Scott Kleper" << endl;

		auto& account3{ db.findAccount(1000) };
	} catch (const std::out_of_range& caughtException) {
		cout << "Unable to find account: " << caughtException.what() << endl;
	}
}