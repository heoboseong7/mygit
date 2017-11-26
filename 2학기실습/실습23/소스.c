#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int value;
	struct node *next;
};

typedef struct node *pnode;
pnode create(int n)
{
	pnode cur;
	cur = (pnode)malloc(sizeof(struct node));

	cur->value = n;
	cur->next = NULL;

	return cur;
}
pnode append(pnode head, pnode cur)
{
	pnode nextnode = head;

	if (head == NULL)
	{
		head = cur;
		return head;
	}

	while (nextnode->next != NULL)
		nextnode = nextnode->next;

	nextnode->next = cur;
	return head;
}

void reverse(pnode head, int n)
{
	pnode nextnode = head;
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			nextnode = nextnode->next;
		}
		printf("%d ", nextnode->value);
		nextnode = head;
	}
}

void center(pnode head, int n)
{
	pnode nextnode = head;
	if (n % 2)
	{
		for (int i = 0; i < (n - 1) / 2; i++)
			nextnode = nextnode->next;
		printf("%d\n", nextnode->value);
	}
	else
	{
		for (int i = 0; i < (n / 2) - 1; i++)
			nextnode = nextnode->next;
		printf("%d %d\n", nextnode->value, nextnode->next->value);
	}
}

void print_fun(pnode head)
{
	pnode nextnode = head;
	while(nextnode != NULL)
	{
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
	}
}

pnode delete_odd(pnode head, int n)
{
	pnode nextnode = head;
	pnode newhead = nextnode->next;
	nextnode = nextnode->next;
	free(head);

	for (int i = 2; i <= n; i++)
	{
		if (i % 2)
		{
			pnode temp = nextnode->next;
			nextnode->next = temp->next;
			nextnode = nextnode->next;
			free(temp);
		}
	}

	return newhead;
}
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

	return 0;
}