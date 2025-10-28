#include <ratio>
#include <iostream>
#include <format>

using namespace std;

int main()
{
	// 컴파일 시간 유리수 정의
	using r1 = ratio<1, 60>;

	// 분자와 분모를 구한다.
	intmax_t num = r1::num;
	intmax_t den = r1::den;
	cout << format("1) r1 = {}/{}", num, den) << endl;

	// 두 유리수를 더한다.
	using r2 = ratio<1, 30>;
	cout << format("2) r2 = {}/{}", r2::num, r2::den) << endl;
	using result = ratio_add<r1, r2>::type;
	cout << format("3) sum = {}/{}", result::num, result::den) << endl;

	// 두 유리수를 비교한다.
	using res = ratio_less<r2, r1>;
	cout << format("4) r2 < r1: {}", res::value) << endl;
}