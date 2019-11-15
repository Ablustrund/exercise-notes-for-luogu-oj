#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int n, a[40][4];
int ans = inf;
bool visited[40];

void dfs(bool ongpu, int left, int num, int res)
{
    if (num == n)
    {
        if (res < ans)
            ans = res;
        return;
    }
    if (res >= ans)
        return;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            if (a[i][0] > left)
                dfs(false, a[i][0] - left, num + 1, res + a[i][0] - left);
            else
                dfs(ongpu, left - a[i][0], num + 1, res);
            visited[i] = false;
        }
    }
    if (ongpu)
    {
        dfs(false, 0, num, res);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            if (a[i][2] > left)
                dfs(true, a[i][2] - left, num + 1, res + a[i][2] - left);
            else
                dfs(true, left - a[i][2], num + 1, res);
            visited[i] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(true, 0, num + 1, res + a[i][3]);
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    dfs(false, 0, 0, 0);
    printf("%d", ans);
    return 0;
}