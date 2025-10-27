#include <iostream>
#include <format>
#include <locale>
#include <sstream>

using namespace std;

int main()
{
	bool result{ isupper('E', locale {"fr-FR"}) };
}