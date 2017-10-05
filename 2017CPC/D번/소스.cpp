#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b)
{
	if (*(double*)a > *(double*)b)
		return 1;
	else if(*(double*)a < *(double*)b)
		return -1;
	else
		return 0;
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	double *score = (double*)malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		scanf("%lf", score + i);

	qsort(score, n, sizeof(double), compare);

	for (i = 0; i < 7; i++)
		printf("%.3lf\n", score[i]);

	return 0;
}