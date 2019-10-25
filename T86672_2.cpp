//score: 80
#include <bits/stdc++.h>
using namespace std;

int n, tempNum, tempFirst, tempSecond, maxx = -1, k = 233333343;
unordered_map<int, int> mapp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        if(mapp.find(tempNum) != mapp.end())
        {
            mapp[tempNum]++;
        }
        else
        {
            mapp[tempNum] = 1;
        }
    }
    unordered_map<int, int>::iterator iter;
    for (iter = mapp.begin(); iter != mapp.end(); iter++)
    {
        tempFirst = iter->first;
        tempSecond = iter->second;
        if (tempSecond > maxx || (tempSecond == maxx && tempFirst < k))
        {
            maxx = tempSecond;
            k = tempFirst;
        }
    }
    printf("%d\n", k);
    return 0;
}