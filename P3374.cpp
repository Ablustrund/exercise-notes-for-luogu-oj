#include <bits/stdc++.h>
using namespace std;

int n, m, choo, tempX, tempY;
int tree[500010];

//树状数组模板
int lowbit(int k)
{
    return k & -k;
}
void add(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while (x != 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tempX);
        add(i, tempX);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &choo, &tempX, &tempY);
        if(choo == 1)
        {
            add(tempX, tempY);
        }
        else
        {
            printf("%d\n", sum(tempY) - sum(tempX - 1));
        }
    }
    return 0;
}