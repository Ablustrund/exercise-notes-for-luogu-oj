#include <bits/stdc++.h>

using namespace std;
int pre[5010];

int Find(int x)
{
    int p, tmp;
    p = x;
    while (x != pre[x])
        x = pre[x];
    while (p != x)
    {
        tmp = pre[x];
        pre[x] = x;
        p = tmp;
    }
    return x;
}

void join(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
        pre[fx] = fy;
}

bool Same(int x, int y)
{
    return Find(x) == Find(y);
}

int main()
{
    int n, m, p, a, b;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        join(a, b);
    }
    for (int i = 1; i <= p; i++)
    {
        scanf("%d%d", &a, &b);
        if(Same(a, b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}