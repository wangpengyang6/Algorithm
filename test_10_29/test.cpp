#define _CRT_SECURE_NO_WARNINGS 1
ģ��

bool check(int x) {/* ... */ } // ���x�Ƿ�����ĳ������

// ����[l, r]�����ֳ�[l, mid]��[mid + 1, r]ʱʹ�ã�
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()�ж�mid�Ƿ���������
        else l = mid + 1;
    }
    return l;
}
// ����[l, r]�����ֳ�[l, mid - 1]��[mid, r]ʱʹ�ã�
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}



#include <iostream>
using namespace std;
const int N = 100010;
int n, q;
int p[N];
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    while (q--)
    {
        int l = 0;
        int r = n - 1;
        int k = 0;
        cin >> k;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (p[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (p[l] != k)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0;
            int r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1; //l = midʱmid��Ҫ��+1��/2
                if (p[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
 
    ���ķ�Χ



#include<iostream>
using namespace std;
int main()
{
    double x;
    cin >> x;
    double l = -10000;
    double r = 10000;
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
        r = mid;
        else
        l = mid;
    }
    printf("%lf", l);
    return 0;
}

�������η���


