#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// ctrl + z = ����
	char a[101];
	while (gets(a))
		puts(a);
	return 0;
}