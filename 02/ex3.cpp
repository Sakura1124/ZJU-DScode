/************************************************************************
*   文件名：ex3.cpp
*   文件描述：多项式的加法和乘法

*   创建人： Sakura, 2020-04-23  
*   版本号：1.0
*   修改记录：
************************************************************************/


#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
    int c;
    int e;
}pnode;

vector<pnode> add( vector<pnode> p1, vector<pnode> p2)
{
    vector<pnode> pt;
    vector<pnode>::iterator it1, it2;
    int sum;
    it1 = p1.begin();
    it2 = p2.begin();
    while( it1 != p1.end() && it2 != p2.end())
    {
        if(it1->e > it2->e) {
            pt.push_back(*it1);
            it1++;
        }
        else if(it1->e < it2->e) 
        {
            pt.push_back(*it2);
            it2++;
        }
        else{
            sum = it1->c + it2->c;
            if( sum){
                pnode t;
                t.c = sum;
                t.e = it1->e;
                pt.push_back(t);
            }  
            it1++;
            it2++;
        }
      
    }
    for(;it1!=p1.end();it1++) pt.push_back(*it1); 
    for(;it2!=p2.end();it2++) pt.push_back(*it2); 
    return pt;
}
vector<pnode> mult( vector<pnode> p1, vector<pnode> p2)
{
    vector<pnode> pt, ps;
    vector<pnode>::iterator it1, it2;
    pnode pp;
    for(it1 = p1.begin(); it1 != p1.end(); it1++)
    {
        for(it2 = p2.begin(); it2 != p2.end(); it2++)
        {
            pp.c = it1->c * it2->c;
            pp.e = it1->e + it2->e;
            ps.push_back(pp);
        }
        
        pt = add(pt, ps);
        ps.clear();
    }
    return pt;
}
void read(vector<pnode> &pt, int n)
{
    while( n--)
    {
        pnode t;
        cin >> t.c >> t.e;
        pt.push_back(t);
    }
}
void print(vector<pnode> pt)
{
    vector<pnode>::iterator it;
    if(pt.empty()) cout <<"0 0";
    int flag = 1;
    for(it = pt.begin(); it != pt.end(); it++)
    {
        if(flag){
            cout << it->c <<" "<< it->e;
            flag = 0;
        }else{
            cout <<" "<< it->c <<" "<< it->e;
        }
        
    }
    cout <<endl; 
}
int main()
{
    int n;
    vector<pnode> p1, p2, pa, ps;

    cin >> n;
    read(p1, n);

    cin >> n;
    read(p2, n);

    ps = mult(p1, p2);
    print(ps);
    pa = add(p1, p2);
    print(pa);
  
}