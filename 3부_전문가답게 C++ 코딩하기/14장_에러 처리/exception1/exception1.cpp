#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void funcOne();
void funcTwo();

int main()
{
	try	{
		funcOne();
	} catch (const exception& e) {
		cerr << "Exception cought!" << endl;
		return 1;
	}
}

void funcOne()
{
	string str1;
	string* str2{ new string {} };

	try {
		funcTwo();
	} catch (...) {
		delete str2;
		throw;
	}
}

void funcTwo()
{
	ifstream fileStream;
	fileStream.open("filename");
	throw exception{};
	fileStream.close();
}