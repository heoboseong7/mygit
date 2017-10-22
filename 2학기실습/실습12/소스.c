#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������� ����ü
struct birthday
{
	int year;
	int month;
	int day;
};

// �������� ����ü
struct personalstatement
{
	char name[30];
	struct birthday date;
	char gender[4];
	char address[30];
	char phonenumber[15];
};
// �̸� ������������ qsort �Լ��� ���� ������ �� �̿��� ���Լ�
int compare_name(const void *a, const void *b)
{
	return (strcmp(((struct personalstatement*)b)->name , ((struct personalstatement*)a)->name));
}
// ���� ������ ������ qsort �Լ��� �̿��� ������ �� �̿��� ���Լ�
int compare_birth(const struct personalstatement *a, const struct personalstatement *b)
{
	if (a->date.year == b->date.year)
		if (a->date.month != b->date.month)
			return (a->date.month - b->date.month);
		else
			return (a->date.day - b->date.day);

	return (a->date.year - b->date.year);
}

int main()
{
	int n;
	struct personalstatement inf[10];
	printf("�Է��� ������ ������ �Է��� �ּ��� :");
	scanf("%d", &n);
	printf("�̸�, �������, ����, �ּ�, ��ȭ��ȣ ������� �Է����ּ��� :\n");
	// n���� ���������� �Է¹޴´�.
	for (int i = 0; i < n; i++)
	{
		scanf("%s", inf[i].name);
		scanf("%d %d %d", &inf[i].date.year, &inf[i].date.month, &inf[i].date.day);
		scanf("%s", inf[i].gender);
		scanf("%s", inf[i].address);
		scanf("%s", inf[i].phonenumber);
	}

	// �Էµ� ������� ���
	printf("\n�̸�\t�������\t����\t�ּ�\t��ȭ��ȣ\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d��%d��%d��\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	// qsort �Լ��� �̿��� �̸� ������������ ���� �� ���
	qsort(inf, n, sizeof(struct personalstatement), compare_name);
	printf("\n�̸�\t�������\t����\t�ּ�\t��ȭ��ȣ - �̸� �������� ����\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d��%d��%d��\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	// qsort �Լ��� �̿��� ���� ������������ ���� �� ���
	qsort(inf, n, sizeof(struct personalstatement), compare_birth);
	printf("\n�̸�\t�������\t����\t�ּ�\t��ȭ��ȣ- ���� �������� ����\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d��%d��%d��\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	return 0;
}