#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 20;
char a[N][N];
bool col[N], dg[N], udg[N];
int n;
void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++) puts(a[i]);
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[x + i] && !udg[i + n - x]) //注意取对角线的第几条边
        {
            a[x][i] = 'Q';
            col[i] = dg[x + i] = udg[i + n - x] = true;
            dfs(x + 1);
            col[i] = dg[x + i] = udg[i + n - x] = false;
            a[x][i] = '.';
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = '.';
    dfs(0);
    return 0;
}