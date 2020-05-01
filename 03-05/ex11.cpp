/************************************************************************
*   文件名：ex11.cpp
*   文件描述：
    完全二叉搜索树
*   创建人： Sakura, 2020-04-29  09:32-11.17
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int N = 1000;
int A[N], T[N];

int getLeftLen(int n)
{
    int h, x;
    h = log2(n + 1);
    x = min(n + 1 - pow(2, h), pow(2, h - 1) );
    return pow(2, h-1) - 1 + x;
}

void solve(int Aleft, int Aright, int Troot)
{
    int n = Aright - Aleft + 1;
    if(n == 0) return;
    int l, Lroot, Rroot;
    l = getLeftLen(n);
    T[Troot] = A[Aleft + l];
    Lroot = Troot*2 + 1;
    Rroot = Lroot + 1;

    solve(Aleft, Aleft + l - 1, Lroot);
    solve(Aleft + l + 1, Aright, Rroot);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A,A+n);
    solve(0, n - 1, 0);
    for (int i = 0; i < n; i++)
    {
        if(i!=0) cout <<" ";
        cout << T[i];
    }
    
    return 0;
}
