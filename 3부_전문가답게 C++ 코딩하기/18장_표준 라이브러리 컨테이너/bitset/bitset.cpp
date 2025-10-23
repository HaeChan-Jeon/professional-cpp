#include <iostream>
#include <bitset>
#include <map>
#include <string>

using namespace std;

class CableCompany final
{
public:
	static const size_t NumChannels{ 10 };
	void addPackage(std::string_view packageName,
		const std::bitset<NumChannels>& channels);
	void addPackage(std::string_view packageName,
		std::string_view channels);
	void removePackage(std::string_view packageName);
	const std::bitset<NumChannels>& getPackage(
		std::string_view packageName) const;
	void newCustomer(std::string_view name, std::string_view package);
	void newCustomer(std::string_view name,
		const std::bitset<NumChannels>& channels);
	void addChannel(std::string_view name, int channel);
	void removeChannel(std::string_view name, int channel);
	void addPackageToCustomer(std::string_view name,
		std::string_view package);
	void deleteCustomer(std::string_view name);
	const std::bitset<NumChannels>& getCustomerChannels(
		std::string_view name) const;
private:
	std::bitset<NumChannels>& getCustomerChannelsHelper(
		std::string_view name);
	using MapType = std::map<std::string, std::bitset<NumChannels>>;
	MapType m_packages, m_customers;
};


void CableCompany::addPackage(std::string_view packageName,
	const std::bitset<NumChannels>& channels)
{
	m_packages.emplace(packageName, channels);
}

void CableCompany::addPackage(std::string_view packageName, std::string_view channels)
{
	addPackage(packageName, bitset<NumChannels> {channels.data()});
}

void CableCompany::removePackage(std::string_view packageName)
{
	m_packages.erase(packageName.data());
}

const std::bitset<CableCompany::NumChannels>& CableCompany::getPackage(
	std::string_view packageName) const
{
	if (auto it {m_packages.find(packageName.data())}; it != end(m_packages)) {
		return it->second;
	}
	throw out_of_range{ "Invalid package"};
}

void CableCompany::newCustomer(std::string_view name, std::string_view package)
{
	auto& packageChannels{ getPackage(package) };
	newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(std::string_view name,
	const std::bitset<CableCompany::NumChannels>& channels)
{
	if (auto [iter, success] {m_customers.emplace(name, channels)}; !success) {
		throw invalid_argument{ "Duplicate customer" };
	}
}

void CableCompany::addChannel(std::string_view name, int channel)
{
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	customerChannels.set(channel);
}

void CableCompany::removeChannel(std::string_view name, int channel)
{
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(std::string_view name, std::string_view package)
{
	auto& packageChannels{ getPackage(package) };
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(std::string_view name)
{
	m_customers.erase(name.data());
}

const std::bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannels(
	std::string_view name) const
{
	if (auto it{ m_customers.find(name.data()) }; it != end(m_customers)) {
		return it->second;
	}
	throw invalid_argument{ "Unknown customer" };
}

std::bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannelsHelper(
	std::string_view name)
{
	return const_cast<bitset<NumChannels>&>(
		as_const(*this).getCustomerChannels(name));
}

int main()
{
	CableCompany myCC;
	myCC.addPackage("basic", "1111000000");
	myCC.addPackage("premium", "1111111111");
	myCC.addPackage("sports", "0000100111");

	myCC.newCustomer("Marc G.", "basic");
	myCC.addPackageToCustomer("Marc G.", "sports");
	cout << myCC.getCustomerChannels("Marc G.") << endl;
}