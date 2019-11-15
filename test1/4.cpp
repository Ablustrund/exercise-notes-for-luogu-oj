#include <bits/stdc++.h>
using namespace std;

const int inf = 100010;
long long int treeNums[inf];
int InPut, r, s, v, n, m, nums[inf];

int lowbit(int k)
{
    return k & -k;
}
void add(int x, int k)
{
    while (x <= n)
    {
        treeNums[x] += k;
        x += lowbit(x);
    }
}
long long int sum(int x)
{
    long long int ans = 0;
    while (x != 0)
    {
        ans += treeNums[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nums[i]);
        add(i, nums[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &InPut);
        if(InPut == 1)
        {
            scanf("%d%d%d", &r, &s, &v);
            if(v == 1) continue;//剪枝
            for (int j = r; j <= s; j++)
            {
                if(nums[j] == 0) continue;//剪枝
                if(nums[j] < v) continue;//剪枝
                if(nums[j] % v == 0)
                {
                    add(j, nums[j] / v - nums[j]);
                    nums[j] /= v;
                }
            }
        }
        else if(InPut == 2)
        {
            scanf("%d%d", &r, &s);
            printf("%lld\n", sum(s) - sum(r - 1));
        }
    }
        return 0;
}