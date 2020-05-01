/************************************************************************
*   文件名：ex20.cpp
*   文件描述：
    dijkstra 变形
*   创建人： Sakura, 2020-04-30  14:02-16.07
*   版本号：1.0
*   修改记录：
    初始化时要全部初始为INF，不是一半！！！
************************************************************************/
#include <iostream>
#include<algorithm>
using namespace std;


#define INF 65535
const int N = 501;

int G[N][N], C[N][N], dist[N], path[N], cost[N];
int vn, em;

int findMinDist(int collected[])
{
    int MinV, v;
    int MinDist = INF;

    for (v = 0; v < vn; v++)
    {
        if (collected[v] == false && dist[v] < MinDist)
        {
            /* 若V未被收录，且dist[v]更小 */
            MinDist = dist[v]; /* 更新最小距离 */
            MinV = v;          /* 更新对应顶点 */
        }
    }
    if (MinDist < INF) /* 若找到最小dist */
        return MinV;        /* 返回对应的顶点下标 */
    else
        return -1; /* 若这样的顶点不存在，返回错误标记 */
}

void Dijkstra(int s)
{
    int collected[N];
    int v, w;

    /* 初始化：此处默认邻接矩阵中不存在的边用INF表示 */
    for (v = 0; v < vn; v++)
    {
        dist[v] = G[s][v];
        cost[v] = C[s][v];
        collected[v] = false;
    }
    /* 先将起点收入集合 */
    dist[s] = 0;
    collected[s] = true;

    while (1)
    {
        /* v = 未被收录顶点中dist最小者 */
        v = findMinDist(collected);
        if (v == -1)                 /* 若这样的V不存在 */
            break;                      /* 算法结束 */
        collected[v] = true;            /* 收录V */
        for (w = 0; w < vn; w++) /* 对图中的每个顶点W */
            /* 若W是V的邻接点并且未被收录 */
            if (collected[w] == false && G[v][w] < INF)
            {
                if (dist[v] + G[v][w] < dist[w])
                {
                    dist[w] = dist[v] + G[v][w]; /* 更新dist[w] */
                  //  path[w] = v;                       
                    cost[w] = cost[v] + C[v][w];
                }else if(dist[v] + G[v][w] == dist[w] &&
                         cost[v] + C[v][w] < cost[w])
                {
                    cost[w] = cost[v] + C[v][w]; 
                   // path[w] = v;  
                }
            }
    }  
}
void creatGC(int &s,int &d)
{
    int m,n,dis,cos;
    cin >> vn >> em >> s >> d;
   
   
    for (int i = 0; i < vn; i++)
    {
        for (int j = 0; j < vn; j++)
        {
            G[i][j] = G[j][i] = INF;
            C[i][j] = C[j][i] = INF;
        }
    }
     for (int i = 0; i < em; i++)
    {
        cin >> m >> n >> dis >> cos;
        G[m][n] = G[n][m] = dis;
        C[m][n] = C[n][m] = cos;
    }
}


int main()
{
    int s, d, m, n, dis, cos;
  
    creatGC(s,d);
  
    Dijkstra(s);
    cout << dist[d]<<" " << cost[d];
    return 0;
}
