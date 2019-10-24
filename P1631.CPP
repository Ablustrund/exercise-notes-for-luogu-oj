#include <bits/stdc++.h>
using namespace std;

int n, tempNum, flag = 1;
vector<int> sequence1, sequence2;
priority_queue<long long int> q;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        sequence1.push_back(tempNum);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        sequence2.push_back(tempNum);
    }
    for (int i = 0; i < n; i++)
    {
        q.push(sequence2[i]);
    }
    while(n--)
    {
        printf("%lld", q.top());
        q.pop();

    }

        printf("\n");
    return 0;
}