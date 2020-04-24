/************************************************************************
*   文件名：ex7.cpp
*   文件描述：输出叶子节点  
    层次遍历修改，只输出叶子节点
*   创建人： Sakura, 2020-04-23  20:06-20.59
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<queue>
using namespace std;


struct node
{
    int data;
    int left;
    int right; 
}t[20];

int buildtree(struct node t[])
{
    int n, root;
    char cl, cr;
    cin >> n;
    if( n == 0) return -1;
    int check[20];
    for( int i = 0; i < n; i++) check[i] = 1;
    if(n){
        for(int i = 0; i < n; i++){
            //check[i] = 1;
            t[i].data = i;
            cin >> cl >> cr;
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
void printleaf( int r)
{
    struct node tmp; 
    if( r != -1){
        queue<struct node> q;
      //  if( t[r].left == -1 && t[r].right == -1) cout << tr[]
        q.push( t[r]);
        int flag = 1;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            if( tmp.left == -1 && tmp.right == -1) {
                if(flag){
                    cout << tmp.data;
                    flag = 0;
                }else{
                    cout <<" "<< tmp.data;
                }
                
            }
            if( tmp.left != -1) q.push(t[tmp.left]);
            if( tmp.right != -1) q.push(t[tmp.right]);
        }
    }
}
int main()
{
   // struct node t[20];
    int r = buildtree(t);
    // for( int i = 0; i < 8; i++) 
    //     cout << t[i].data <<" "<< t[i].left <<" " << t[i].right << endl;
   // cout << r;
    printleaf(r);
    return 0;
}
