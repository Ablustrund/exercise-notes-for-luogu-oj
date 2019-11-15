#include <bits/stdc++.h>
using namespace std;

int n, tempV, tempX, tree1[20010], tree2[20010];
//运用算法：树状数组，离散化。(开一个和 值的最大值 一样大的数组)
struct cow
{
    int v = 0, x = 0;
} cows[20010];

bool cmp(cow a, cow b)
{
    if(a.v != b.v) return a.v < b.v;
    return a.x < b.x;
}

long long int lowBit(int k)
{
    return k & -k;
}

void addTree1(int x, int k)
{
    while(x <= 20000)
    {
        tree1[x] += k;
        x += lowBit(x);
    }
}

long long int sumTree1(int x)
{
    long long int ans = 0;
    while(x != 0)
    {
        ans += tree1[x];
        x -= lowBit(x);
    }
    return ans;
}

void addTree2(int x, int k)
{
    while(x <= 20000)
    {
        tree2[x] += k;
        x += lowBit(x);
    }
}

long long int sumTree2(int x)
{
    long long int ans = 0;
    while(x != 0)
    {
        ans += tree2[x];
        x -= lowBit(x);
    }
    return ans;
}

int main()
{
    long long int ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &cows[i].v, &cows[i].x);
    sort(cows + 1, cows + n + 1, cmp);
    addTree1(cows[1].x, cows[1].x);
    addTree2(cows[1].x, 1);
    for(int i = 2; i <= n; i++)
    {
        //树状数组tree1[i]:坐标为i的值为坐标i(离散化),为了求其比i小的数组方便，只需要sum(0-i)
        //树状数组tree2[i]:坐标为i的地方有没有人sum就是坐标小于i的所有地方一共有多少个人
        addTree1(cows[i].x, cows[i].x);
        addTree2(cows[i].x, 1);
        int test1 = sumTree2(cows[i].x - 1);
        int test2 = sumTree1(cows[i].x - 1);
        int test3 = i - 1 - sumTree2(cows[i].x - 1);
        int test4 = sumTree1(20000) - cows[i].x - sumTree1(cows[i].x - 1);
        ans += cows[i].v * (cows[i].x * sumTree2(cows[i].x - 1) - sumTree1(cows[i].x - 1) - cows[i].x * (i - 1 - sumTree2(cows[i].x - 1)) + (sumTree1(20000) - cows[i].x - sumTree1(cows[i].x - 1)));
    }
    printf("%lld\n", ans);
    return 0;
}