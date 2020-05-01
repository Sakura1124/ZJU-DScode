/************************************************************************
*   文件名：ex19.cpp
*   文件描述：
    save007  无权最短路 
    单独处理第一跳。题目要求存在多个最短时，输出第一跳的距离最小，可以把所有点距原点距离从小到大排序，
*   创建人： Sakura, 2020-04-30  09:23-12.20
*   版本号：1.0
*   修改记录：
************************************************************************/

#include <iostream>
#include<stack>
#include<queue>
using namespace std;

#define INF 65535

int dis, vn, path[100], D[100];
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

void printPath(int v)
{
    stack<int> s; 
    cout << D[v]+1 <<endl;
    while (v != -2)
    {
        s.push(v);
        v = path[v];
    }
   
    while (!s.empty())
    {
        cout << p[s.top()].x <<" "<<p[s.top()].y <<endl;
        s.pop();
    }
       
}
int findMin(int v, int w)
{
    int i = v, j = w;
    if(v == -1) return w;
    while (path[v]!=-2)
    {
        v = path[v];
    }
    while (path[w]!=-2)
    {
        w = path[w];
    }
    struct point centre(0,0);
    return distance(centre, p[v]) < distance(centre, p[w]) ? i : j;
    
    
}
void unweighed()
{
    int v;
    queue<int> q;
    for (int i = 0; i < vn; i++)
    {
        if(firstJump(i))
        {
            D[i] = 1;
            q.push(i);
        }
    }
    if(dis > 42){
        cout << 1 <<endl;
        return;
    }
    
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for (int i = 0; i < vn; i++)
        {
            if (i!=v && jump(v, i))
            {
                if(D[i] == -1){
                    D[i] = D[v] + 1;
                    path[i] = v;
                    q.push(i);
                }
            }
        }
    }
    // cout << vn <<endl;
    // for (int i = 0; i < vn; i++)
    // {
    //     if(isSave(i)) cout <<i <<" dist:"<<D[i] <<" ";
    // }
    // cout <<endl;
    
    int min = INF, t = -1;
    for (int i = 0; i < vn; i++)
    {
        if(isSave(i) && D[i] != -1 && D[i] <= min){
            if(D[i] == min){
                t = findMin(t, i);
            }else{
                t = i;
                min = D[i];
            }
            
        }
    }
    if(t == -1) cout << 0 <<endl;
    else printPath(t);    
}

void save007()
{
    for (int i = 0; i < 100; i++) //初始化
    {
        D[i] = -1;
        path[i] = -2;
    }
    unweighed(); 
}
int main()
{
    cin >> vn >> dis;
    struct point centre(0, 0);
    for (int i = 0; i < vn; i++)
    {
        cin >> p[i].x >> p[i].y;
        if (max(abs(p[i].x), abs(p[i].y)) >= 50 || distance(p[i], centre) < 7.5*7.5)	//此处是为了淘汰掉那些不在水中的点；
        {
            vn--;
            i--;
        }
    }
    // for (int i = 0; i < vn; i++)
    // {
    //     cout << i <<": " <<p[i].x <<","<<p[i].y<<endl;
    // }
    // return 0;
    
    save007();
    return 0;
}
