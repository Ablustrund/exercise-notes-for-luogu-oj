#include <bits/stdc++.h>
using namespace std;

int pre[1010];

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

struct node
{
    int x, y, t;
    node(int _x, int _y, int _t)
    {
        x = _x;
        y = _y;
        t = _t;
    }
};

vector<node> vec;
bool cmp(node a, node b)
{
    return a.t < b.t;
}
int main()
{
    int n, m, a, b, x, y, t;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &t);
        vec.push_back(node(x, y, t));
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        a = Find(vec[i].x);
        b = Find(vec[i].y);
        if(a != b)
        {
            join(vec[i].x, vec[i].y);
            n--;
            if(n == 1)
            {
                printf("%d\n", vec[i].t);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}