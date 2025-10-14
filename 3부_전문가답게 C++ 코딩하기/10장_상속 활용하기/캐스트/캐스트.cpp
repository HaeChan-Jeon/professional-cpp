#include <iostream>
#include <bit>

using namespace std;

int main()
{
	float asFloat{ 1.23f };
	auto asUnit{ bit_cast<unsigned int>(asFloat) };
	if (bit_cast<float>(asUnit) == asFloat)
	{
		cout << "Roundtrip success." << endl;
	}
}