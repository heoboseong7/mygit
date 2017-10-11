#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int compare(const void *a, const void *b)
{
	return (strcmp(((personalstatement*)b)->name , ((personalstatement*)a)->name));
}

int compare2(const void *a, const void *b)
{
	if (((personalstatement*)a)->date.year > (((personalstatement*)b)->date.year))
		return 1;
	else if (((personalstatement*)a)->date.year < (((personalstatement*)b)->date.year))
		return -1;
	else if (((personalstatement*)a)->date.year == (((personalstatement*)b)->date.year))
		if (((personalstatement*)a)->date.month > (((personalstatement*)b)->date.month))
			return 1;
		else if (((personalstatement*)a)->date.month < (((personalstatement*)b)->date.month))
			return -1;
		else if (((personalstatement*)a)->date.month == (((personalstatement*)b)->date.month))
			if (((personalstatement*)a)->date.day > (((personalstatement*)b)->date.day))
				return 1;
			else if (((personalstatement*)a)->date.day < (((personalstatement*)b)->date.day))
				return -1;
			else if (((personalstatement*)a)->date.day == (((personalstatement*)b)->date.day))
				return 0;
}
int main()
{
	int n;
	personalstatement inf[10];
	printf("입력할 정보의 개수를 입력해 주세요 :");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", inf[i].name);
		scanf("%d %d %d", &inf[i].date.year, &inf[i].date.month, &inf[i].date.day);
		scanf("%s", inf[i].gender);
		scanf("%s", inf[i].address);
		scanf("%d", &inf[i].phonenumber);
	}

	printf("이름\t생년월일\t성별\t주소\t\t\t\t전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d-%d-%d\t%s\t%s\t0%d\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}
	qsort(inf, n, sizeof(personalstatement), compare);

	printf("이름\t생년월일\t성별\t주소\t\t\t\t전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d-%d-%d\t%s\t%s\t0%d\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	qsort(inf, n, sizeof(personalstatement), compare2);
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d-%d-%d\t%s\t%s\t0%d\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	return 0;
}