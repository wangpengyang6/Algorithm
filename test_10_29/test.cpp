#define _CRT_SECURE_NO_WARNINGS 1
模板

bool check(int x) {/* ... */ } // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
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
                int mid = l + r + 1 >> 1; //l = mid时mid需要再+1再/2
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
 
    数的范围



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

数的三次方根


