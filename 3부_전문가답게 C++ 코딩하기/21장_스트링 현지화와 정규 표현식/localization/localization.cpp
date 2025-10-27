#include <iostream>
#include <format>
#include <locale>
#include <sstream>

using namespace std;

int main()
{
	auto upper{ toupper('e', locale {"fr-FR"}) };
}