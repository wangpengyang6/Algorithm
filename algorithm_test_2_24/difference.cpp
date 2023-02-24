#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int n, m;
const int N = 100010;
int a[N];
int b[N];
int main()
{
    cin >> n >> m;
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + b[i];
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

}