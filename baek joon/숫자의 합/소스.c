#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);

	int c, d = 0, e = 0;

	for (c = a - 1; c >= 0; c--)
	{
		e = b / pow(10, c);
		d = d + e;
		b = b - e * pow(10, c);
	}
	
	printf("%d\n", d);
}