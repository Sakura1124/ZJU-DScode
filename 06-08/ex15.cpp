/************************************************************************
*   文件名：ex15.cpp
*   文件描述：列出联通子集
    邻接矩阵存储，分别用dfs， bfs 遍历

*   创建人： Sakura, 2020-04-26  11:38-12.49
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<queue>
using namespace std;

int visited[10000];

void dfs(int g[][20], int v, int n)
{
    int i;
    visited[v] = 1;
    cout << v << " ";
    for (i = 0; i < n; i++)
    {
        if (g[v][i] && !visited[i])
        {
            dfs(g, i, n);
        }
    }
}

void bfs(int g[][20], int v, int n)
{
    int tmp;
    queue<int> q;
    visited[v] = 1;
    cout << v << " ";
    q.push(v);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[tmp][i] && !visited[i])
            {
               visited[i] = 1;
               cout << i << " ";
               q.push(i);
            }
        }
    }
}
void componentsdfs(int g[][20], int v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout <<"{ ";
            dfs(g, i, n);
            cout <<"}"<<endl;
        }
        
    }
    
}
void componentsbfs(int g[][20], int v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout <<"{ ";
            bfs(g, i, n);
            cout <<"}"<<endl;
        }
        
    }
}
int main()
{
    int vn, en, count = 0, m, n;
    cin >> vn >> en;
    int graph[20][20];
    for (int i = 0; i < vn; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < en; i++)
    {
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    componentsdfs(graph, 0, vn);

    for (int i = 0; i < vn; i++)
    {
        visited[i] = 0;
    }
    componentsbfs(graph, 0, vn);
    return 0;
}
