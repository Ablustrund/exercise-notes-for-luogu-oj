#include <bits/stdc++.h>
using namespace std;

//同样这道题也是被老师骗过来了。。。我太菜了完全不懂为什么这道题和树状数组有关系
priority_queue<int, vector<int>, less<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;
int n, mid, tempNum;

int main()
{
    scanf("%d%d", &n, &mid);
    printf("%d\n", mid);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &tempNum);
        if (tempNum <= mid)
        {
            q1.push(tempNum);
        }
        else
            q2.push(tempNum);
        if (i % 2 == 0)
        {
            while (q1.size() != q2.size())
            {
                if (q1.size() < q2.size())
                {
                    q1.push(mid);
                    mid = q2.top();
                    q2.pop();
                }
                else
                {
                    q2.push(mid);
                    mid = q1.top();
                    q1.pop();
                }
            }
            printf("%d\n", mid);
        }
    }
    return 0;
}