#include <bits/stdc++.h>
using namespace std;

int n, k;
int tempL, tempM, tempH, tempA;
struct people
{
    int ident;
    int length, money, handsome, age;
    people(int _ident = 0, int _length = 0, int _money = 0, int _handsome = 0, int _age = 0)
    {
        ident = _ident;
        length = _length;
        money = _money;
        handsome = _handsome;
        age = _age;
    }
};

people peoples[1000010];

// bool operator < (people a, people b)
// {
//     if(a.handsome != b.handsome) return a.handsome > b.handsome;
//     else if(a.length != b.length) return a.length > b.length;
//     else if(a.money != b.money) return a.money > b.money;
//     return a.age < b.age;
// }

//priority_queue<people, vector<people>, less<people>> q;

bool cmp(people a, people b)
{
    if (a.handsome != b.handsome) return a.handsome > b.handsome;
    else if (a.length != b.length) return a.length > b.length;
    else if (a.money != b.money) return a.money > b.money;
    return a.age < b.age;
}

int main()
{
    // scanf("%d%d", &n, &k);
    // for (int i = 1; i <= n; i++)
    // {
    //     scanf("%d%d%d%d", &tempL, &tempM, &tempH, &tempA);
    //     q.push(people(i, tempL, tempM, tempH, tempA));
    //     if(i > k)
    //     {
    //         q.pop();
    //     }
    // }
    // stack <int> s;
    // for (int i = 0; i < k; i++)
    // {
    //     s.push(q.top().ident);
    //     q.pop();
    // }
    // while(!s.empty())
    // {
    //     printf("%d ", s.top());
    //     s.pop();
    // }

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        peoples[i].ident = i + 1;
        scanf("%d%d%d%d", &peoples[i].length, &peoples[i].money, &peoples[i].handsome, &peoples[i].age);
    }
    sort(peoples, peoples + n, cmp);
    for (int i = 0; i < k; i++)
        printf("%d ", peoples[i].ident);
    return 0;
}