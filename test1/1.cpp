#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200010;
int father[maxn], dis[maxn], minn = 1000000000;
int n, tempNum;

int find(int x)
{
    if (father[x] != x)
    {
        int last = father[x];
        father[x] = find(father[x]);
        dis[x] += dis[last];
    }
    return father[x];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tempNum);
        int x = find(i), y = find(tempNum);
        if (x != y)
        {
            father[x] = y;
            dis[i] = dis[tempNum] + 1;
        }
        else minn = min(minn, dis[i] + dis[tempNum] + 1);
    }
    cout << minn;
    return 0;
}