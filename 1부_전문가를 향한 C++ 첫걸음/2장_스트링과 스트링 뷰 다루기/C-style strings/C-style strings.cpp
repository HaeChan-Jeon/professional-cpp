#include <cstring>
#include <cstddef>
#include <iostream>

int main()
{
    char text1[]{ "abcdef" };
    size_t s1{ sizeof(text1) };
    size_t s2{ strlen(text1) };
    std::cout << s1 << std::endl; // 7이다.
    std::cout << s2 << std::endl; // 6이다.
    std::cout << std::endl;

    const char* text2 { "abcdef" };
    size_t s3{ sizeof(text2) };
    size_t s4{ strlen(text2) };
    std::cout << s3 << std::endl; // 8이다(플랫폼 마다 다름. 포인터의 크기).
    std::cout << s4 << std::endl; // 6이다.
    std::cout << std::endl;

}

char* copyString(const char* str)
{
    size_t len{ strlen(str) + 1};
    char* result{ new char[len] };
    strcpy_s(result, len, str);
    return result;
}

char* appendStrings(const char* str1, const char* str2, const char* str3)
{
    const size_t len{ strlen(str1) + strlen(str2) + strlen(str3) + 1 };
    char* result{ new char[len] };
    strcpy_s(result, len, str1);
    strcat_s(result, len, str2);
    strcat_s(result, len, str3);
    return result;
}