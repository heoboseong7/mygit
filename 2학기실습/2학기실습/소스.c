#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int choose;
	int a, b;
	int temp;
	do {
		printf("����� �����ϼ���.\n0. Exit\n1. Temporary variable\n2. Addition/subtraction\n3. Multiply/division\n4. Exclusive OR\n\n");

		scanf("%d", &choose);

		switch (choose) {
		case 0:
			break;
		// Temporary variable
		case 1:
			printf("�� ������ �Է��ϼ���\n");
			scanf("%d %d", &a, &b);
			temp = a;
			a = b;
			b = temp;
			printf("��� : %d %d\n", a, b);
			break;
		// Addition/subtraction
		case 2:
			printf("�� ������ �Է��ϼ���\n");
			scanf("%d %d", &a, &b);
			a = a + b;
			b = a - b;
			a = a - b;
			printf("%��� : d %d\n", a, b);
			break;
		// Multiply/division
		case 3:
			printf("�� ������ �Է��ϼ���\n");
			scanf("%d %d", &a, &b);
			a = a * b;
			b = a / b;
			a = a / b;
			printf("��� : %d %d\n", a, b);
			break;
		// Exclusive OR
		case 4:
			printf("�� ������ �Է��ϼ���\n");
			scanf("%d %d", &a, &b);
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			printf("��� : %d %d\n", a, b);
		//1 ~ 4 �̿��� �� �Է½� ����� ��������
		default:
			break;
		}
	} while (1 <= choose && choose <= 4);
	
	return 0;
}