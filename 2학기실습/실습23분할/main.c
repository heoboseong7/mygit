#include "header.h"

int main()
{
	int cnt = 0;
	int n;
	pnode head = NULL;
	pnode cur;

	printf("�������� �Է��� �ּ��� : ");
	while (scanf("%d", &n) != EOF)
	{
		cur = create(n);
		head = append(head, cur);
		cnt++;
	}

	printf("�Էµ� �ڷ��� ����\n%d\n", cnt);
	printf("�������� ���\n");
	reverse(head, cnt);
	printf("\n�߰���ġ�� ��\n");
	center(head, cnt);
	printf("�Էµ� ������� ���\n");
	print_fun(head);
	printf("\nȦ�� ��° node�� �����ϰ� ���\n");
	head = delete_odd(head, cnt);
	print_fun(head);
	printf("\n");

	return 0;
}