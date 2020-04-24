/************************************************************************
*   文件名：BST.cpp
*   文件描述：二叉搜索树操作

    查找，最大，最小，插入，删除

*   创建人： Sakura, 2020-04-24  12:47
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST, ElementType X )
{
    if (!BST)
    { /*若原树为空，生成并返回一个结点的二叉搜索树*/
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else  if (X < BST->Data) /*开始找要插入元素的位置*/
        BST->Left = Insert(BST->Left, X); /*递归插入左子树*/
    else if (X > BST->Data)
        BST->Right = Insert(BST->Right, X); /*递归插入右子树*/ /* else X已经存在，什么都不做 */
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)
{
    Position Tmp;
    if (!BST)
        printf("Not Found\n");
    else if (X < BST->Data)
        BST->Left = Delete(BST->Left, X); /* 左子树递归删除 */
    else if (X > BST->Data)
        BST->Right = Delete( BST->Right, X); /* 右子树递归删除 */
    else /*找到要删除的结点 */ if (BST->Left && BST->Right)
    {                              /*被删除结点有左右两个子结点 */
        Tmp = FindMin(BST->Right); /*在右子树中找最小的元素填充删除结点*/
        BST->Data = Tmp->Data;
        BST->Right = Delete(BST->Right, BST->Data); /*在删除结点的右子树中删除最小元素*/
    }
    else
    { /*被删除结点有一个或无子结点*/
        Tmp = BST;
        if (!BST->Left) /* 有右孩子或无子结点*/
            BST = BST->Right;
        else if (!BST->Right) /*有左孩子或无子结点*/
            BST = BST->Left;
        free(Tmp);
    }
    return BST;
}
Position Find(BinTree BST, ElementType X)
{
    if (!BST)
        return NULL; /*查找失败*/
    if (X > BST->Data)
        return Find(BST->Right, X); /*在右子树中继续查找*/
    else if (X < BST->Data)
        return Find(BST->Left, X); /*在左子树中继续查找*/
    else                           /* X == BST->Data */
        return BST;                /*查找成功，返回结点的找到结点的地址*/
}
Position FindMin(BinTree BST)
{
    if (!BST)
        return NULL; /*空的二叉搜索树，返回NULL*/
    else if (!BST->Left)
        return BST; /*找到最左叶结点并返回*/
    else
        return FindMin(BST->Left); /*沿左分支继续查找*/
}
Position FindMax(BinTree BST)
{
    if (BST)
        while (BST->Right)
            BST = BST->Right; /*沿右分支继续查找，直到最右叶结点*/
    return BST;
}

void PreorderTraversal( BinTree BT )
{
    if(BT){
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal( BinTree BT )
{
    if(BT){
        PreorderTraversal(BT->Left);
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Right);
    }
}