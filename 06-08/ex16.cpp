/************************************************************************
*   文件名：ex16.cpp
*   文件描述：
    dfs应用
*   创建人： Sakura, 2020-04-26  14:46
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
using namespace std;

int dis, vn, visited[100];
struct point{
    int x, y;
    point(){};
    point(int x, int y):x(x), y(y){};
};
struct point p[100];
int distance(struct point a, struct point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int firstJump(int v)
{
    struct point centre(0,0);
    if (distance(centre, p[v]) <= (7.5 + dis) * (7.5 + dis)) return 1;
    else return 0;
}
int isSave(int v)
{
    if(50-p[v].x <= dis || p[v].x+50 <= dis || 50-p[v].y <= dis || p[v].y+50 <= dis) return 1;
    else return 0;
}
int jump(int v, int w)
{
    if(distance(p[v], p[w]) <= dis*dis) return 1;
    else return 0;
}
int dfs(int v)
{
    int ans;
    visited[v] = 1;
    if (isSave(v))
        ans = 1;
    else
    {
        for (int i = 0; i < vn; i++)
        {
            if (i != v && !visited[i] && jump(i, v))
            {
                ans = dfs(i);
                if (ans) break;
            }
        }
    }
    return ans;
}
int save007()
{
    int ans = 0;
    for (int i = 0; i < vn; i++)
    {
        if(!visited[i] && firstJump(i))
        {
            ans = dfs(i);
            if(ans) break;
        }
    }
    return ans;
    
}
int main()
{
    cin >> vn >> dis;
    
    for (int i = 0; i < vn; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    if(save007()) cout <<"Yes";
    else cout << "No";
    return 0;
}
