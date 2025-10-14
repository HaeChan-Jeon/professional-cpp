#include <iostream>

int main()
{
	int i{ 3 };
	int j{ 4 };
	double result{ static_cast<double>(i) / j };
	std::cout << result;
}