
#include <bits/stdc++.h>
using namespace std;

long long int DP[1010][6]; //在所有的15中情况中只有6中情况才能出现。
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        DP[i][0] = 1;
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][1] * 2) % 999999997;
        DP[i][2] = (DP[i - 1][0] + DP[i - 1][2]) % 999999997;
        DP[i][3] = (DP[i - 1][1] + DP[i - 1][3] * 2) % 999999997;
        DP[i][4] = (DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][4] * 2) % 999999997;
        DP[i][5] = (DP[i - 1][3] + DP[i - 1][4] + DP[i - 1][5] * 2) % 999999997;
    }
    printf("%lld\n", DP[n][5]);
    return 0;
}