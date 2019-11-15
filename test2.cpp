#include <iostream>
using namespace std;

int block[16];
int ans = 2000;
bool judge()
{
    int counts = 0;
    for (int i = 0; i < 16; i++)
    {
        counts += block[i];
    }
    if(counts == 0 || counts == 16)
    {
        return true;
    }
    else return false;
}

void reverse(int k)
{
    block[k] = !block[k];
    if(k + 1 <= 15 && k / 4 == (k + 1) / 4) block[k + 1] = !block[k + 1];
    if(k - 1 >= 0 && k / 4 == (k - 1) / 4) block[k - 1] = !block[k - 1];
    if(k + 4 <= 15) block[k + 4] = !block[k + 4];
    if(k - 4 >= 0) block[k - 4] = !block[k - 4];
}

void func(int k, int tempAns)
{
    if(k > 15) return;
    if(judge() == true)
    {
        if(tempAns < ans) ans = tempAns;
    }
    func(k + 1, tempAns);
    reverse(k);
    if(judge() == true)
    {
        if(tempAns + 1 < ans) ans = tempAns + 1;
    }
    func(k + 1, tempAns + 1);
    reverse(k);
}

int main()
{
    char ch;
    for(int i = 0; i < 16; i++)
    {
        cin >> ch;
        if(ch == 'w') block[i] = 0;
        else if(ch == 'b') block[i] = 1;
    }
    func(0, 0);
    if(ans == 2000) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}