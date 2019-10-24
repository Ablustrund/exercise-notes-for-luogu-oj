#include <bits/stdc++.h>
using namespace std;

int n, tempNum, counts[10010], k = 0 , maxx = -1;
bool exist[10010] = {false};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        counts[tempNum]++;
        exist[tempNum] = true;
    }
    for (int i = 1; i <= 10010; i++)
    {
        if(exist[i] && maxx < counts[i])
        {
            maxx = counts[i];
            k = i;
        }
    }
    printf("%d\n", k);
    return 0;
}