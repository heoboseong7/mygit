#include <iostream>
using namespace std;

int main()
{
	int money;
	while(1)
	{
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end) : ";
		cin >> money;
		if (money == -1)
			break;
		cout << "�̹� �� �޿� : " << 50 + money * 0.12 << endl;
	}

	return 0;
}