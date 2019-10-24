#include <bits/stdc++.h>
using namespace std;

int visited[1000010];
int n, tempNum, numCount = 0;
int main()
{
    fill(visited, visited + 1000010, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        if(tempNum > 0)
        {
            if(visited[tempNum] == -1) numCount++;
            else visited[tempNum] = 1;
        }
        else
        {
            tempNum = 0 - tempNum;
            if(visited[tempNum] == 1) numCount++;
            else visited[tempNum] = -1;
        }
    }
    printf("%d\n", numCount);
    return 0;
}