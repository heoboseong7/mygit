#include <iostream>

using namespace std;

int main()
{
	const int num = 12;
	const int *ptr = &num;
	const int *&ref = ptr;

	cout << *ptr << endl;
	cout << *ref << endl;

	return 0;
}