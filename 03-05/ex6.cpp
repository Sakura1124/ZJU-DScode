/************************************************************************
*   文件名：ex6.cpp
*   文件描述：树的同构判别

*   创建人： Sakura, 2020-04-23  18:43-19.39
*   版本号：1.0
*   修改记录：
不考虑如果左右儿子数据相等的情况
************************************************************************/
#include <iostream>
using namespace std;

struct node
{
    char data;
    int left;
    int right; 
}t1[10], t2[10];

int buildtree(struct node t[])
{
    int n, root;
    char cl, cr;
    cin >> n;
    if( n == 0) return -1;
    int check[n];
    if(n){
        for(int i = 0; i < n; i++){
            check[i] = 1;
            cin >> t[i].data >> cl >> cr;
            if(cl != '-'){
                t[i].left = cl - '0';
                check[t[i].left] = 0;
            }else{
                t[i].left = -1;
            }

            if(cr != '-'){
                t[i].right = cr - '0';
                check[t[i].right] = 0;
            }else{
                t[i].right = -1;
            }
        }
        int i;
        for(i = 0; i < n; i++) if(check[i]) break;
        root = i;
    }
    return root;
}
int isomorphic( int r1, int r2)
{
    if( r1 == -1 && r2 == -1) return 1;   //两颗空树
    if( (r1 == -1 && r2 != -1) || (r1 != -1 && r2 == -1)) return 0; //   一颗空树                             
    if( t1[r1].data != t2[r2].data ) return 0; //根数据不同
    if( t1[r1].left == -1 && t2[r2].left == -1) return isomorphic( t1[r1].right, t2[r2].right); //左子树均空，判断右字数
   // if( t1[r1].left == -1 && t2[r2].right == -1) return isomorphic( t1[r1].right, t2[r2].left); 
    if( ( t1[r1].left != -1 && t2[r2].left != -1) && (t1[t1[r1].left].data == t2[t2[r2].left].data))  //左子树非空且根数据相等
        return isomorphic(t1[r1].left, t2[r2].left) && isomorphic(t1[r1].right, t2[r2].right);
    else                                                                                              //左子树非空但数据不等
        return isomorphic(t1[r1].left, t2[r2].right) && isomorphic(t1[r1].right, t2[r2].left);
}
int main()
{
    int n, r1, r2;
    r1 = buildtree(t1);
    r2 = buildtree(t2);
    if(isomorphic(r1, r2)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
