#include <iostream>
#include <cstring>

using namespace std;

void makeacc();
void depositmoney();
void withdrawmoney();
void showallaccinfo();

typedef struct
{
	int accid;
	int balance;
	char name[20];
}acc;

acc account[100];
int accn = 0;

int main()
{
	int choice;
	while (1)
	{
		cout << "----Menu----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			makeacc();
			break;
		case 2:
			depositmoney();
			break;
		case 3:
			withdrawmoney();
			break;
		case 4:
			showallaccinfo();
			break;
		case 5:
			return 0;
		default :
			cout << "����� �� ���� �Է��� �ּ���." << endl;
		}
		cout << endl;
	}
	return 0;
}

void makeacc()
{
	cout << "[�� �� �� ��]" << endl;
	cout << "���� ID : ";
	cin >> account[accn].accid;
	cout << "�̸� : ";
	cin >> account[accn].name;
	cout << "�Աݾ� : ";
	cin >> account[accn].balance;

	accn++;
}

void depositmoney()
{
	int cmpid;
	int money;
	int i;
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> cmpid;
	for(i = 0; i <  accn; i++)
		if (cmpid == account[i].accid)
			break;
	if (i == accn + 1)
	{
		cout << "��ȿ���� ���� ID �Դϴ�." << endl;
		return;
	}

	cout << "�Աݾ� : ";
	cin >> money;
	account[i].balance += money;
}

void withdrawmoney()
{
	int i;
	int cmpid;
	int money;
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> cmpid;
	for (i = 0; i < accn; i++)
		if (cmpid == account[i].accid)
			break;
	if (i == accn + 1)
	{
		cout << "��ȿ���� ���� ID �Դϴ�." << endl;
		return;
	}
	cout << "��ݾ� : ";
	cin >> money;
	if (account[i].balance < money)
		cout << "�ܾ� ����" << endl;
	else
	{
		account[i].balance -= money;
		cout << "��� �Ϸ�" << endl;
	}
}

void showallaccinfo()
{
	for (int i = 0; i < accn; i++)
	{
		cout << "����ID : " << account[i].accid << endl;
		cout << "�� ��  : " << account[i].name << endl;
		cout << "�� ��  : " << account[i].balance << endl;
	}
}