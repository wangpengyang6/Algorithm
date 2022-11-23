#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Judge(int arr[1000][1000], int x, int y, int n)
{
	int i = 0;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= n; j++)
		{
			sum = sum + arr[j][i];
		}
		if (sum == 0 && i != y)
			return 1;
		sum = 0;

	}
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= n; j++)
		{
			sum = sum + arr[i][j];
		}
		if (sum == 0 && i != x)
			return 1;
		sum = 0;
	}

	return 0;

}

int Judge2(int arr[1000][1000], int x, int y, int n)
{
	int i = 0;
	int sum = -2;
	for (i = 1; i <= n; i++)
	{
		sum = sum + arr[x][i] + arr[i][y];
	}
	if (sum == 0)
		return 1;
	else
		return 0;
}


int arr[1000][1000] = { 0 };

char* brr[2000];
int main()
{
	int t = 0;
	scanf("%d",&t);
	int i = 0;
	for (i = 0; i < t; i++)
	{
		int n, m;
		int count = 0;
		scanf("%d %d",&n,&m);
		int j = 0;
		int k = 0;
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				arr[j][k] = 0;
			}
		}
		for (j = 0; j < m; j++)
		{
			int x = 0;
			int y = 0;
			scanf("%d %d",&x,&y);
			arr[x][y] = 1;
		}
		for (j = 0; j < m; j++)
		{
			int l = 0;
			for (k = 1; k <= n; k++)
			{
				for (l = 1; l <= n; l++)
				{
					if (arr[k][l] == 1 && Judge2(arr,k,l,n))
					{
						if (Judge(arr, k, l,n))
						{
							count++;
						}
					}
				}
			}
		}
		if (count)
		{
			brr[i] = "YES";
		}
		else
			brr[i] = "NO";
	}
	for (i = 0; i < t; i++)
	{
		printf("%s\n",brr[i]);
	}
	return 0;
}