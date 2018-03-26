#include "header.h"

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);

	int *a;
	a = (char*)malloc(sizeof(int) * n);
	_reverse(a, d, n);
	printarr(a, n);
	free(a);
	return 0;
}