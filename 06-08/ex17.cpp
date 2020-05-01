/************************************************************************
*   文件名：ex17.cpp
*   文件描述：
    六度空间  BFS应用
*   创建人： Sakura, 2020-04-28  14:32-15.44
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<iomanip>
#include<queue>
using namespace std;

const int N = 1001;

int graph[N][N];
int visited[N];
int vn, en;
int bfs(int v)
{
    int vt, count;
    int level = 0, last = v, tail;
    queue<int> q;
    visited[v] = 1;
    q.push(v);
    count = 1;
    while (!q.empty())
    {
        vt = q.front();
        q.pop();
        for (int i = 1; i <= vn; i++)
        {
            if (graph[vt][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
                count++;
                tail = i;
            }
        }
        if( vt == last ){
            level++;
            last = tail;
        }
        
        if(level == 6) break;
    }
    return count;
}

void sds()
{
    int count;
    for (int i = 1; i <= vn; i++)
    {
        count = bfs(i);
        cout <<i<<": "<<fixed<<setprecision(2) <<count*100.0/vn <<"%"<< endl;
        cout.unsetf(ios::fixed);
        for (int j = 1; j <= vn; j++)
        {
            visited[j] = 0;
        }
        
    }
    
}

int main()
{
    int  m, n;
    cin >> vn >> en;
    for (int i = 0; i < en; i++)
    {
        cin >> m >> n;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    sds();
    
    return 0;
}
