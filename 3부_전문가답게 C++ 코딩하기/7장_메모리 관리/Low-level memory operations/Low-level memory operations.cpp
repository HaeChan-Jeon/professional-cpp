int main()
{
	int* myArray{ new int[8] };
	myArray[2] = 33;
	*(myArray + 2) = 33;

	const wchar_t* myString{ L"Hello, World" };
}