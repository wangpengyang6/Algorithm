#define _CRT_SECURE_NO_WARNINGS 1
void quick_sort(int p[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1;
    int j = r + 1;
    int x = p[(l + r) / 2];
    while (i < j)
    {
        do
        {
            i++;
        } while (p[i] < x);
        do
        {
            j--;
        } while (p[j] > x);
        if (i < j)
        {
            swap(p[i], p[j]);
        }
    }
    quick_sort(p, l, j);
    quick_sort(p, j + 1, r);

}

快速排序






void merge_sort(int p[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(p, l, mid);
    merge_sort(p, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (p[i] <= p[j])
            tmp[k++] = p[i++];
        else
            tmp[k++] = p[j++];
    }
    while (i <= mid)
        tmp[k++] = p[i++];
    while (j <= r)
        tmp[k++] = p[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        p[i] = tmp[j];
    }
}

归并排序





#include<iostream>
using namespace std;
const int N = 100010;
int n;
int k;
int p[N];
void quick_sort(int p[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1;
    int j = r + 1;
    int x = p[(l + r) / 2];
    while (i < j)
    {
        do i++; while (p[i] < x);
        do j--; while (p[j] > x);
        if (i < j)
            swap(p[i], p[j]);
    }
    quick_sort(p, l, j);
    quick_sort(p, j + 1, r);
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    quick_sort(p, 0, n - 1);
    printf("%d", p[k - 1]);
    return 0;
}

第k个数



#include<iostream>
using namespace std;
const int N = 100010;
int n;
int p[N];
int tmp[N];
typedef long long LL;
LL merge_sort(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (p[i] <= p[j])
            tmp[k++] = p[i++];
        else
        {
            tmp[k++] = p[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        tmp[k++] = p[i++];
    }
    while (j <= r)
        tmp[k++] = p[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        p[i] = tmp[j];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    cout << merge_sort(0, n - 1) << endl;
    return 0;
}


逆序对数量