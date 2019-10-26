#include <bits/stdc++.h>
using namespace std;

int pre[30010], summ[30010], preNum[30010];
int T, tempI, tempJ, fx, fy;
char ch;

int Find(int n)
{
    if (pre[n] == n)
        return pre[n];
    int fn = Find(pre[n]);
    preNum[n] += preNum[pre[n]];
    return pre[n] = fn;
}

int main()
{
    cin >> T;
    for (int i = 1; i < 30010; i++)
    {
        pre[i] = i;
        preNum[i] = 0;
        summ[i] = 1;
    }
    while (T--)
    {
        cin >> ch >> tempI >> tempJ;
        fx = Find(tempI);
        fy = Find(tempJ);
        if (ch == 'M')
        {
            preNum[fx] += summ[fy];
            pre[fx] = fy;
            summ[fy] += summ[fx];
            summ[fx] = 0;
        }
        if (ch == 'C')
        {
            if (fx != fy)
                cout << "-1" << endl;
            else
                cout << abs(preNum[tempI] - preNum[tempJ]) - 1 << endl;
        }
    }
    return 0;
}