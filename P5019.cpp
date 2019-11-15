//这道题应该使用dp？但是为什么老师会把这道题放在树状数组里面呢。。不懂。。另外dalao们说的差分是什么鬼
#include <bits/stdc++.h>
using namespace std;

//dp[i] = preNum >= nowNum ? dp[i - 1] : dp[i - 1] + nowNum - preNum
int n, preNum, nowNum, dp;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nowNum);
        if(preNum < nowNum) dp += (nowNum - preNum);
        preNum = nowNum;
    }
    printf("%d\n", dp);
}