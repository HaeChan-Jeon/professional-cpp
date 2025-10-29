#include <iostream>
#include <random>

using namespace std;

using mt19937 = mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31,
	0x9908b0df, 11, 0xffffffff, 7, 0x9d2c5680, 15, 0xefc60000, 18,
	1812433252>;

int main()
{
	random_device rnd;
	cout << "Entropy: " << rnd.entropy() << endl;
	cout << "Min value: " << rnd.min()
		<< ", Max value: " << rnd.max() << endl;
	cout << "Random number: " << rnd() << endl;
}