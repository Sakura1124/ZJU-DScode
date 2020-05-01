/************************************************************************
*   文件名：ex18.cpp
*   文件描述：
*   创建人： Sakura, 2020-04-29  20:12
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<math.h>
using namespace std;

#define INF 65535

const int N = 1000;
int G[N][N], path[N][N], D[N][N];

void floyd(int n)
{
     for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            D[i][j] = G[i][j];
            //path[i][j] = -1;
        }
    }
    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    //path[i][j] = k;
                }
            }
        }
    }
}

void findMax(int n)
{
    int c, r, t, min = INF, max, flag;
    for (int i = 1; i < n + 1; i++)
    {
        flag = 1;
        max = 0;
        for (int j = 1; j < n + 1; j++)
        {
            
            if (D[i][j] == INF)
            {
                flag = 0;
                break;
            }
            if (D[i][j] > max)
            {
                t = j;
                max = D[i][j];
            }
        }
        if (max < min)
        {
            c = i;
            r = t;
            min = max;
        }
    }
    if (flag)
    {
        cout << c << " " << D[c][r];
    }
    else
    {
        cout << 0;
    }
}
int main()
{
    int m, n, v, w, cost;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if( i == j ) G[i][j] = 0;
            else    G[i][j] = INF;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        cin >> v >> w >> cost;
        G[v][w] = G[w][v] = cost;
    }
   
    //  for (int i = 1; i < n+1; i++)
    // {
    //     for (int j = 1; j < n+1; j++)
    //     {
    //         cout << D[i][j] <<" ";
    //     }
    //     cout <<endl;
        
    // }
    floyd(n);
    // for (int i = 1; i < n+1; i++)
    // {
    //     for (int j = 1; j < n+1; j++)
    //     {
    //         cout << D[i][j] << " ";
    //     }
    //     cout <<endl;
        
    // }
    
    findMax(n);
    return 0;
}
