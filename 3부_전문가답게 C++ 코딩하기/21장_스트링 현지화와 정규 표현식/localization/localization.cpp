#include <iostream>
#include <locale>

using namespace std;

int main()
{
	locale locUSEng{ "en-US" };
	locale locBritEng{ "en-GB" };

	wstring dollars{ use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol() };
	wstring pounds{ use_facet<moneypunct<wchar_t>>(locBritEng).curr_symbol() };

	wcout << L"In the US, the currency simbol is " << dollars << endl;
	wcout << L"In Great Britatin, the currency simbol is " << pounds << endl;
}