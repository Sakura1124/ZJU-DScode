/************************************************************************
*   文件名：ex8.cpp
*   文件描述：
    参考：https://github.com/Heliovic/PAT_Solutions/blob/master/1086/main.cpp
*   创建人： Sakura, 2020-04-24  08:12-11.23
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;
int N;
vector<int> post;

struct node
{
    int data;
    node* r;
    node* l;
    node() {r = l = NULL;}
};

node* create()
{
    if (N == 0)
        return NULL;
    string op;
    int d;
    cin >> op;
    N--;
    if (op == "Push")
    {
        node* n = new node;
        cin >> d;
        stk.push(d);
        n->l = create();
        n->data = stk.top();
        stk.pop();
        n->r = create();
        return n;
    }
    else
        return NULL;
}

void post_order(node* r)
{
    if (r == NULL)
        return;
    post_order(r->l);
    post_order(r->r);
    post.push_back(r->data);
}

int main()
{
    cin >> N;
    N *= 2;
    node* root = create();
    post_order(root);
    for (int i = 0; i < post.size(); i++)
    {
        if (i != 0)
           cout << " ";
        cout << post[i];
    }
    return 0;
}
/*
void preorder( int t)
{
    if(t){
        cout<< t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(int bt)
{
    t = bt;
    while(t || !s.empty())
    {
          while(t)
        {
            s.push(t);
            t = t->left;
        }
        if(!s.empty()){
            t = s.pop();
            if(t->right == p || t->right == NULL) //后序加个if判断
            {
                cout << t->data;
                p = t ;
                t = NULL; 
            }else{
                s.push(t);
                t=t->right;
            }
        }
    }
}
*/