/************************************************************************
*   文件名：ex11.cpp
*   文件描述：打印堆中路径
*   创建人： Sakura, 2020-04-25  16:41-17.19
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
using namespace std;

const int MAXSIZE = 10001;
const int MINX = -10001;

int heap[MAXSIZE], sz;

void create()
{
    sz = 0;
    heap[0] = MINX;
}

void insert(int x)
{
    int i;
    for (i = ++sz; heap[i / 2] > x; i /= 2)
    {
        heap[i] = heap[i / 2];
    }
    heap[i] = x;
}
int main()
{
    int n, m, x, t;
    cin >> n >> m;
    create();
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        for (int i = t; i > 0; i /= 2)
        {
            if (i != t)
                cout << " ";
            cout << heap[i];
        }
        cout << endl;
    }

    return 0;
}
