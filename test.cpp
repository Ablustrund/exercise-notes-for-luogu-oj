#include <iostream>
using namespace std;

int block[2][2]; //1:black, 0:white
int ans = 1000000000;
int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[4][4];
int allCount = 0;

bool judge()
{
    int countt = 0;
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 2; jj++)
        {
            countt = countt + block[ii][jj];
        }
    }
    if(countt == 0 || countt == 4) return 1;
    else return 0;
}

void reverse(int i, int j)
{
    block[i][j] = !block[i][j];
    for(int ii = 0; ii < 4; ii++)
    {
        int xx = i + direc[ii][0];
        int yy = j + direc[ii][1];
        if(xx >= 0 && xx <= 1 && yy >= 0 && yy <= 1) block[xx][yy] = !block[xx][yy];
    }
    for (int ii = 0; ii < 2; ii++)
    {
        for(int jj = 0; jj < 2; jj++)
        {
            printf("%d", block[ii][jj]);
        }
        printf("\n");
    }
}

void dfs(int i, int j, int tempAns)
{
    if(tempAns > 4)
        return;
    int xx, yy;
    if (i < 0 || j < 0 || i > 1 || j > 1)
        return;
    if (visited[i][j])
        return;
    allCount++;

    if (judge())
    {
        if (ans > tempAns) ans = tempAns;
    }

    visited[i][j] = true;
    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (!visited[xx][yy])
        {
            dfs(xx, yy, tempAns);
        }
    }

    reverse(i, j);

    if (judge())
    {
        if (ans > tempAns) ans = tempAns + 1;
    }

    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (!visited[xx][yy])
        {
            dfs(xx, yy, tempAns + 1);
        }
    }

    reverse(i, j);
    visited[i][j] = false;
    return;
}

int main()
{
    char ch;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%c", &ch);
            if (ch == 'b')
                block[i][j] = 1;
            else if (ch == 'w')
                block[i][j] = 0;
        }
        getchar();
    }
    dfs(0, 0, 0);
    if (ans == 1000000000)
        printf("Impossible\n");
    else
        printf("%d\n", ans);
    printf("%d\n", allCount);
    return 0;
}