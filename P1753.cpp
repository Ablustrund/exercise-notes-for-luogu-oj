#include <iostream>
using namespace std;

int block[4][4]; //1:black, 0:white
int ans = 1000000000;
int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[4][4];
int allCount = 0;

void dfs(int i, int j, int tempAns)
{
    if(tempAns > 16)
        return;
    int xx, yy;
    if (i < 0 || j < 0 || i > 3 || j > 3)
        return;
    if (visited[i][j])
        return;
    int tempCount = 0;
    allCount++;

    for (int ii = 0; ii < 4; ii++)
    {
        for (int jj = 0; jj < 4; jj++)
        {
            tempCount = tempCount + block[ii][jj];
        }
    }
    if (tempCount == 0 || tempCount == 16)
    {
        if (ans > tempAns)
            ans = tempAns;
        return;
    }

    visited[i][j] = true;
    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (!visited[xx][yy])
        {
            //visited[xx][yy] = true;
            dfs(xx, yy, tempAns);
            //visited[xx][yy] = false;
        }
    }

    block[i][j] = !block[i][j];
    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (xx >= 0 && xx < 4 && yy >= 0 && yy < 4)
        {
            block[xx][yy] = !block[xx][yy];
        }
    }

    tempCount = 0;
    for (int ii = 0; ii < 4; ii++)
    {
        for (int jj = 0; jj < 4; jj++)
        {
            tempCount = tempCount + block[ii][jj];
        }
    }
    if (tempCount == 0 || tempCount == 16)
    {
        if (ans > tempAns)
        {
            ans = tempAns + 1;
        }
        block[i][j] = ! block[i][j];
        for (int ii = 0; ii < 4; ii++)
        {
            xx = i + direc[ii][0];
            yy = j + direc[ii][1];
            if (xx >= 0 && xx < 4 && yy >= 0 && yy < 4)
            {
                block[xx][yy] = !block[xx][yy];
            }
        }
        visited[i][j] = false;
        return;
    }

    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (!visited[xx][yy])
        {
            //visited[xx][yy] = true;
            dfs(xx, yy, tempAns + 1);
            //visited[xx][yy] = false;
        }
    }

    block[i][j] = !block[i][j];
    for (int ii = 0; ii < 4; ii++)
    {
        xx = i + direc[ii][0];
        yy = j + direc[ii][1];
        if (xx >= 0 && xx < 4 && yy >= 0 && yy < 4)
        {
            block[xx][yy] = !block[xx][yy];
        }
    }
    visited[i][j] = false;
    return;
}

int main()
{
    char ch;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
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