#include <iostream>
#include <map>
#include <queue>
using namespace std;

int n, tempNum, tempSite, flag = 1;
vector<int> sequence1, sequence2;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int site[100010];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        sequence1.push_back(tempNum);
    }
    sequence1.push_back(0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        sequence2.push_back(tempNum);
    }
    sequence2.push_back(0);
    for (int i = 0; i < n; i++)
    {
        q.push(make_pair(sequence1[i]+sequence2[0], i));
    }
    while(n--)
    {
        if(flag)
        {
            printf("%d", q.top().first);
            flag--;
        }
        else printf(" %d", q.top().first);
        tempSite = q.top().second;
        site[tempSite]++;
        q.pop();
        q.push(make_pair(sequence2[site[tempSite]] + sequence1[tempSite], tempSite));
    }
    printf("\n");
    return 0;
}