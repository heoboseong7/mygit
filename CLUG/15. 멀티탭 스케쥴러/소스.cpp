#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
int compare(int a, int n, int *plug, int *tempplug, int ncnt)
{
	int tf = 0;

	for (int j = 0; j < ncnt; j++)
		if (tempplug[j] == a)
			return 0;
		else
			tf++;

	if (tf == ncnt)
		for (int i = 0; i < n; i++)
			if (plug[i] == a)
				return 0;

	return 1;
}
*/
int compare2(int a, int n, int *plug)
{	
	for (int i = 0; i < n; i++)
		if (plug[i] == a)
			return i;

	return 0;
}

int main()
{
	int n, k;
	int cnt = 1;
	int ncnt = 0;
	int i, j = 0;
	int plug[21] = { 0 };
	int tempplug[21] = { 0 };
	int name[101] = { 0 };
	//int same[21]

	scanf("%d %d", &n, &k);

	for (i = 0; i < k; i++)
		scanf("%d", name + i);

	// 첫번째 플러그 값 받기
	plug[0] = name[0];

	// 초기값 n개 설정
	while (cnt != n)
	{
		for (i = 0; i < cnt; i++)
		{

			if (plug[i] != name[j])
			{
				plug[cnt++] = name[j++];
				break;
			}
			j++;
		}
	}

	//카운트 초기화
	cnt = 0;
	/*
	for (i = n - 1; i < k; i++)
	{
		if (compare(name[i], n, plug, tempplug, ncnt))
		{
			tempplug[ncnt] = name[i];
			ncnt++;
			cnt++;
			if (ncnt == n)
			{
				while (ncnt--)
				{
					plug[n - ncnt - 1] = tempplug[n - ncnt - 1];
					tempplug[n - ncnt - 1] = 0;
				}
				ncnt = 0;
			}
		}
	}
	*/

	for (i = n - 1; i < k; i++)
	{
		if (compare2(name[i], n, plug) == 0)
		{
			cnt++;
			for (j = i + 1; j < i + n; j++)
				if (compare2(name[j], ncnt, plug) != 0)
					tempplug[ncnt++] = compare2(name[j], ncnt, plug);
				else
					cnt++;

			for (j = 0; j < n; j++)
				if (tempplug[j] == 0)
					plug[j] = name[tempplug[j]];

			i += n - 1;
		}
	}
	printf("%d", cnt);

	return 0;
}