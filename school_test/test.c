#define _CRT_SECURE_NO_WARNINGS 1



                                   A
#include<stdio.h>
int main()
{
    int n, na, nb;
    scanf("%d %d %d",&n,&na,&nb);
    int a[100] = {0};
    int b[100] = {0};
    int i = 0;
    int ia = 0;
    int ib = 0;
    int count_a = 0, count_b = 0;
    for (i = 0; i < na;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < nb; i++)
    {
        scanf("%d",&b[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (ia == na)
            ia = 0;
        if (ib == nb)
            ib = 0;
        if (a[ia] - b[ib] == -2 || a[ia]- b[ib] == 5 || a[ia]-b[ib] == -3)
        {
            count_a++;
        }
        if (b[ib] - a[ia] == -2 || b[ib] - a[ia] == 5 || b[ib] - a[ia] == -3)
        {
            count_b++;
        }
        ia++;
        ib++;
    }
    if (count_a > count_b)
    {
        printf("A");
    }
    else if (count_a < count_b)
    {
        printf("B");
    }
    else
    {
        printf("draw");
    }
    return 0;
}



                                   B
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int m = 0;
	int flag = 0;
	scanf("%d %d", &n, &m);
	int* num = (int*)malloc(sizeof(int) * n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		num[i] = 1;
	}
	for (j = 2; j<=m; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (i % j == 0)
			{
				num[i-1] *= (-1);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (num[i] == 1)
		{
			if (flag == 0)
			{
				printf("%d", i + 1);
				flag = 1;
			}
			else
			printf(",%d", i + 1);
		}
	}
	return 0;
}


								   C

#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d",&n);
	int arr[3] = { 3,5,7 };
	int brr[3] = { 0 };
	int j = 0;
	int count = 0;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (n % arr[i] == 0)
		{
			count++;
			brr[j++] = arr[i];
		}
	}
	if (count == 0)
		printf("n\n");
	for (i = 0; i < count; i++)
	{
		printf("%d ",brr[i]);
	}
	return 0;
}

								   D
#include<stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int arr[100][100] = {0};
	int brr[100][100] = {0};
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			scanf("%d", &brr[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			printf("%d ",arr[i][j] + brr[i][j]);
		}
		printf("\n");
	}
	return 0;
}


								   E

#include<stdio.h>

int ret = 0;

int mul(int arr[100][100], int brr[100][100], int i, int m, int j)
{
	int k = m;
	if (k >= 0)
	{
		int tem = arr[i][k] * brr[k][j];
		ret += tem;
		mul(arr, brr, i, m - 1, j);
	}

	return ret;
}
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int A[100][100] = { 0 };
	int B[100][100] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		int j = 0;
		for (j = 0; j < k; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < k; j++)
		{
			printf("%d ", mul(A, B, i, m-1, j));
			ret = 0;
		}
		printf("\n");
	}
	return 0;
}


								   F

#include<stdio.h>
struct People
{
	char name[10];
	float tem;
	int i;
}Peo[200];
int main()
{
	int n = 0;
	scanf("%d",&n);
	int i = 0;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s %f %d", Peo[i].name, &(Peo[i].tem), &(Peo[i].i));
	}
	for (i = 0; i < n; i++)
	{
		if (Peo[i].tem >= 37.5)
		{
			if (Peo[i].i == 1)
			{
				printf("%s\n", Peo[i].name);
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}


								G
#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d %d",&n,&m);
	int sum = n + m;
	int ret = 0;
	while (ret = n % m)
	{
		n = m;
		m = ret;
	}
	printf("%d",sum-m);
	return 0;
}

