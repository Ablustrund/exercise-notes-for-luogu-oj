#include <bits/stdc++.h>
using namespace std;

int n, m, choo, x, y, k;
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
    int preNum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        //建立差分数组
        add(i, x - preNum);
        preNum = x;
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &choo);
        if(choo == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        }
        else if(choo == 2)
        {
            scanf("%d", &x);
            printf("%d\n", sum(x));//差分数组：单点查询点x的值就是在差分数组中查询前x项和，也就是用sum(x)函数就可以完成查询.
        }
    }
        return 0;
}