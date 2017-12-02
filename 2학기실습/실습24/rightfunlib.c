#include "header.h"

void rtrivial(int arr[], int d, int n)
{
	int temp;
	for (int i = 0; i < d; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - d + i];
		arr[n - d + i] = temp;
	}
}

void rjuggling(int arr[], int d, int n)
{
	int k;
	for (int i = 0; i < gcd(n, d); i++)
	{
		int j = i;
		int temp = arr[i];
		while (1)
		{
			k = (j + d) % n;

			if (k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

void rblock_swap(int arr[], int d, int n)
{
	if (d == n || d == 0)
		return;

	if (n - d == d)
	{
		swap(arr, 0, n - d, d);
		return;
	}
	else if (n - d > d)
	{
		swap(arr, 0, n - d, d);
		rblock_swap(arr, d, n - d);
	}
	else
	{
		swap(arr, 0, d, n - d);
		rblock_swap(arr + n - d, 2 * d - n, d);
	}
}

