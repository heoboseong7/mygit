#include <stdio.h>
#include <stdlib.h>

int main()
{

	int cnt = 0;
	int k;
	printf("�ʱ� ������ �Է� : ");
	scanf("%d", &k);
	char *test = (char*)malloc(k);
	int sum = 0;
	while (1)
	{
		//����� ���̻� ���� �� ���� �� �ݺ����� �������´�.
		if (k == 0)
			break;
		// �޸� �Ҵ��� �������� ��� ����� ������ ���δ�.
		if (test == NULL)
		{
			k = k / 2;
			printf("�����޸� �Ҵ� ��û ����, ����� ������ ����\n");
			cnt = 0;
		}
		// �޸� �Ҵ��� ����� ���� ��� ������ 1���� ������� �ش� ������� �Ҵ���� ������ ����ϰ�
		// ���� sum�� �ش� ����� ���Ͽ� �Ҵ�� �� �޸� ���� ���Ѵ�.
		else
		{
			sum += k;
			printf("���� 1���� ������ : %d Bytes  �ش� ������� �Ҵ���� ���� : %d �� \n", k, ++cnt);
		}
		test = (char*)malloc(k);
	}
	printf("���̻� ���� �� ����\n");
	printf("���ݱ��� �Ҵ���� �޸��� �� : %d Bytes\n", sum);
	free(test);
	return 0;
}