#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char arr[1001];
	cin >> arr;
	for (int i = 0; i < strlen(arr); i++) {
		if (i > 0 && i % 10 == 0)
			cout << endl;
		cout << arr[i];
	}
	return 0;
}