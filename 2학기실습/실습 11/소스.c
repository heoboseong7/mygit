#include <stdio.h>
struct birthday
{
	int year;
	int month;
	int day;
};
struct personalstatement
{
	char name[30];
	struct birthday date;
	char gender[4];
	char address[30];
	int phonenumber;
};
int main()
{
	struct personalstatement inf = { "�㺸��",{ 1998, 12, 9 }, "��", "��û�ϵ� ���ֽ� �߿���� 3379", 1030048506 };
	printf("�̸� : %s\n", inf.name);
	printf("������� : %d�� %d�� %d��\n", inf.date.year, inf.date.month, inf.date.day);
	printf("���� : %s\n", inf.name);
	printf("�ּ� : %s\n", inf.address);
	printf("��ȭ��ȣ : 0%d\n\n", inf.phonenumber);

	printf("�̸�\t�������\t����\t�ּ�\t\t\t\t��ȭ��ȣ\n");
	printf("%s\t%d-%d-%d\t%s\t%s\t0%d", inf.name, inf.date.year, inf.date.month, inf.date.day, inf.gender, inf.address, inf.phonenumber);

	return 0;
}