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
	char phonenumber[15];
};

int compare(const void *a, const void *b)
{
	return (strcmp(((struct personalstatement*)b)->name , ((struct personalstatement*)a)->name));
}

int compare_short(const struct personalstatement *a, const struct personalstatement *b)
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
	printf("입력할 정보의 개수를 입력해 주세요 :");
	scanf("%d", &n);
	printf("이름, 생년월일, 성별, 주소, 전화번호 순서대로 입력해주세요 :\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%s", inf[i].name);
		scanf("%d %d %d", &inf[i].date.year, &inf[i].date.month, &inf[i].date.day);
		scanf("%s", inf[i].gender);
		scanf("%s", inf[i].address);
		scanf("%s", inf[i].phonenumber);
	}

	printf("\n이름\t생년월일\t성별\t주소\t전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}
	qsort(inf, n, sizeof(struct personalstatement), compare);

	printf("\n이름\t생년월일\t성별\t주소\t전화번호 - 이름 내림차순 정렬\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	qsort(inf, n, sizeof(struct personalstatement), compare_short);

	printf("\n이름\t생년월일\t성별\t주소\t전화번호- 생일 오름차순 정렬\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	return 0;
}