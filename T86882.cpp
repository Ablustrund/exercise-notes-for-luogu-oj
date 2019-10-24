#include <bits/stdc++.h>
using namespace std;

int n, tempNum, numbers[10000010], counts;
bool exists[10000010];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        exists[tempNum] = true;
        if(tempNum == 0)
            if(exists[1]) counts++;
        else if(tempNum == 10000000)
            if(exists[9999999]) counts++;
        else
        {
            if(exists[tempNum - 1]) counts++;
            if(exists[tempNum + 1]) counts++;
        }
    }
    printf("%d\n", counts);
    return 0;
}