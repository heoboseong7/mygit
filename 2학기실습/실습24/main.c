#include "header.h"

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);

	int *a;
	a = (int*)malloc(sizeof(int) * n);
	gendata(a, n);
	printarr(a, n);
	rblock_swap(a, d, n);
	printarr(a, n);
	free(a);
	return 0;
}