#define _CRT_SECURE_NO_WARNINGS 1

//1.DFS：递归结束条件的选择 + 状态标记 + 递归后的恢复
//2.BFS：模拟队列 q[N], d[N] 使用d数组标记状态
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 110;
int a[N][N], b[N][N];
int n, m;
queue<pair<int, int>> q;
int A[4] = { 0,-1,0,1 }, B[4] = { 1,0,-1,0 };
int bfs()
{
    memset(b, -1, sizeof b);

    b[0][0] = 0;
    q.push({ 0,0 });

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + A[i];
            int y = t.second + B[i];
            if (x >= 0 && x < n && y >= 0 && y < m && b[x][y] == -1 && a[x][y] == 0)
            {
                b[x][y] = b[t.first][t.second] + 1;
                q.push({ x,y });
            }
        }
    }
    return b[n - 1][m - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    cout << bfs() << endl;
    return 0;
}