#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char name[100];
	char email[1000];
}information;

int main()
{
	char fname[] = "test.bin";
	information me;
	FILE *f;
	// ó�� �� ǥ�� �Է����� �Է¹ޱ�
	fopen_s(&f, fname, "wb");
	printf("�̸��� �Է��ϼ��� : ");
	fgets(me.name, 100, stdin);
	printf("email�� �Է��ϼ��� : ");
	fgets(me.email, 1000, stdin);

	//���� ���Ͽ� ����
	fwrite(&me, sizeof(information), 1, f);

	//���� �ݱ�
	fclose(f);

	//����� ���� ���� �ٽ� ��� �б�
	printf("-----------------------------------------\n");
	printf("���� �� ��� ���\n");
	printf("-----------------------------------------\n");
	fopen_s(&f, fname, "rb");
	information test;
	fread(&test, sizeof(information), 1, f);
	printf("�̸� : %s", test.name);
	printf("email : %s", test.email);

	fclose(f);

	return 0;
}