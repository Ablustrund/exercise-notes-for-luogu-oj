#include <bits/stdc++.h>
using namespace std;

int n, m, tempSecond, flag = 1;
int a[10010], b[10010], c[10010], nowX[10010];//队列中存放的函数i的函数值是由now[i]计算出来的
priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int main()
{
    fill(nowX, nowX + 10010, 1);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        q.push(make_pair(a[i] + b[i] + c[i], i));//数据first来自函数编号i
    }
    for (int i = 0; i < m; i++)
    {
        if(flag)
        {
            printf("%d", q.top().first);
            flag = 0;
        }
        else printf(" %d", q.top().first);
        tempSecond = q.top().second;
        nowX[tempSecond]++;
        q.pop();
        q.push(make_pair(a[tempSecond] * nowX[tempSecond] * nowX[tempSecond] + b[tempSecond] * nowX[tempSecond] + c[tempSecond], tempSecond));
    }
    printf("\n");
    return 0;
}