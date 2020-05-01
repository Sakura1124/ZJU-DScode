/************************************************************************
*   文件名：ex13.cpp
*   文件描述：并查集
*   创建人： Sakura, 2020-04-25  21:36
*   版本号：1.0
*   修改记录：
    递增链答案错误
    交换下union里的r1,r2解决？？？？？
************************************************************************/
#include <iostream>
using namespace std;

const int MAX = 10000;

int find(int s[], int x)
{
    for(; s[x] > 0; x=s[x]);
    return x;
}
void Union(int s[], int r1, int r2) //按规模
{
   /* s[r1] = r2;
    return;*/
    if (r1 != r2)
    {
        if (s[r1] < s[r2])
        {
            s[r1] += s[r2];
            s[r2] = r1;
        }
        else
        {
            s[r2] += s[r1];
            s[r1] = r2;
        }
    }
}
void inputConnection(int s[])
{
    int a, b, r1, r2;
    cin >> a >> b;
    r1 = find(s, a-1);
    r2 = find(s, b-1);
    Union(s, r1, r2);
}
void checkConnection(int s[])
{
    int a, b;
    cin >> a >> b;
    if (find(s, a-1) == find(s, b-1))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
void checkNetwork(int s[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] < 0) {
            count++;
           // cout << "s[" << i << "] = "<< s[i];
        }
    }
    if(count == 1) cout << "The network is connected.";
    else cout << "There are " << count <<" components.";
    
}
void initSet(int s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = -1;
    }
    
}
int main()
{
    int set[MAX], n;
    char in;
    cin >> n;
    initSet(set, n);
    do{
        cin >> in;
        switch (in)
        {
            case 'I':inputConnection(set);break;
            case 'C':checkConnection(set);break;
            case 'S':checkNetwork(set, n);break;
        }
    }while(in!='S');
    return 0;
}
