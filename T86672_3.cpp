#include <bits/stdc++.h>
using namespace std;

int n, j, tempNum, maxx, maxxCount = -1;
vector<int> numbers;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempNum);
        numbers.push_back(tempNum);
    }
    sort(numbers.begin(), numbers.end() ,cmp);
    for (int i = 0; i < n;)
    {
        tempNum = numbers[i];
        j = 0;
        while(i < n && numbers[i] == tempNum)
        {
            j++;
            i++;
        }
        if(j > maxxCount)
        {
            maxxCount = j;
            maxx = tempNum;
        }
    }
    printf("%d\n", maxx);
    return 0;
}