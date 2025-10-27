#include <iostream>
#include <format>

using namespace std;

int main()
{
	// 확장 문자
	wchar_t myWideCharacter{ L'm' };
	wcout << L"I am a wide-character string Literal." << endl;

	// 스트링 리터널 현지화하기
	size_t n{ 5 };
	wstring filename{ L"file1.txt" };
	wcout << L"Read " << n << L" bytes from " << filename << endl;
	cout << format(loadResource(IDS_TRANSFERRED), n, filename) << endl;
}