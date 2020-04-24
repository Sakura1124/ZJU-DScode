#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
Position binarysearch( List l, ElementType x, Position start, Position end)
{
    int center = (start + end)/2;
    if( start > end) return NotFound;
    if( l->Data[center] == x) return center;
    else if(l->Data[center] > x){
        return binarysearch(l, x, start, center-1);
    }else{
        return binarysearch(l, x, center+1, end);
    }
}
Position BinarySearch( List l, ElementType x)
{
    return binarysearch(l, x, 1, l->Last);
}