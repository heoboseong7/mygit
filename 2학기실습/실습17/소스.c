#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char fname[] = "test.txt";
	FILE *f;
	int cnt = 0;
	int i = 0;
	char line[100][80] = { { NULL } };
	if (fopen_s(&f, fname, "r") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	};

	fgets(line[0], 80, f);
	while (*line[i] != NULL)
	{
		fgets(line[++i], 80, f);
	}
	fclose(f);

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	};

	for (int j = 0; j < i; j++)
	{
		fprintf(f, "%d. ", j + 1);
		fputs(line[j], f);
	}
	return 0;
}