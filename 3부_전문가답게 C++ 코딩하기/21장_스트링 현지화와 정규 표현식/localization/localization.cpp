#include <iostream>
#include <format>

using namespace std;

int main()
{
	const char8_t* s1{ u8R"(Raw UTF-8 encoded string literal)" };
	const wchar_t* s2{ LR"(Raw wide string literal)" };
	const char16_t* s3{ uR"(Raw char16_t encoded string literal)" };
	const char32_t* s4{ UR"(Raw char32_t encoded string literal)" };

	const char8_t* formula{ u8"\u03c0 r\u00B2" };
}