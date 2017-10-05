#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int a[100001];
	int b[100001];
	int time[100001];
	int max;

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", a + i, b + i);
		time[i] = b[i] - a[i];
	}
	return 0;
}