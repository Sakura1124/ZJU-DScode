/************************************************************************
*   文件名：ex9.cpp
*   文件描述：判断是否是同一颗二叉树
*   创建人： Sakura, 2020-04-24  14:45-16.43
*   版本号：1.1
*   修改记录：
    判断完一个序列后要恢复flag，否则会影响后续判断
************************************************************************/
#include <iostream>
#include <vector>
using namespace std;



typedef struct node
{
    int data, flag;
    struct node *left;
    struct node *right;
    node(){ left = NULL; right = NULL; flag = 0;}
}bintree;


bintree* insert(int x, bintree *bst)
{

    if (!bst)
    { /*若原树为空，生成并返回一个结点的二叉搜索树*/
        bst = new bintree;
        bst->data = x;
    }else if (x < bst->data) /*开始找要插入元素的位置*/
        bst->left = insert(x, bst->left); /*递归插入左子树*/
    else if (x > bst->data)
        bst->right = insert(x, bst->right); /*递归插入右子树*/ /* else X已经存在，什么都不做 */
    return bst;
}
bintree* buildtree(int n)
{
    bintree *t = NULL;
    int d;
    // cin >> d;
    // t = new bintree;
    // t->data = d;
    for(int i = 0; i < n; i++){
        cin >> d;
        t = insert(d, t);
    }
    return t;
}
void freetree(bintree *bst)
{
    if(bst){
        if(bst->left == NULL && bst->right == NULL) delete bst;
        else{
            freetree(bst->left);
            freetree(bst->right);
            delete bst;
        }
    }
}
void flagreset(bintree *bst)
{
    if (bst)
    {
        bst->flag = 0;
        flagreset(bst->left);
        flagreset(bst->right);
    }
}

int check(int x, bintree *bst)
{
    if (bst->flag){
        if (x > bst->data)
            return check(x, bst->right); /*在右子树中继续查找*/
        else if (x < bst->data)
            return check(x, bst->left); /*在左子树中继续查找*/
        else return 0;  //出现重复数字认为不一致
    }else{
        if(x == bst->data){
            bst->flag = 1;
            return 1;
        }else return 0;
    }                           
}
int judge(int n, bintree *bst)
{
    int d, flag = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> d;
        if(!flag && !check(d, bst)) flag = 1;;
    }
    if(flag) return 0;
    return 1;
}
int main()
{
    int n, c, d;
    
    vector<int> result;
    bintree *tree;
    cin >> n;
    while(n)
    {   
        cin >> c;
        tree = buildtree(n);
        while(c--)
        {   
            result.push_back(judge(n, tree)); 
            flagreset(tree);   
        }
        freetree(tree); 
        cin >> n; 
    }
    for(int i = 0; i < result.size(); i++) 
    if(result[i]) cout << "Yes" <<endl;
    else cout << "No" <<endl;
   
    return 0;
}
