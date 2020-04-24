
#include<stdio.h>

List Merge( List L1, List L2 );

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List p = L1->Next,q = L2->Next;
	L1 -> Next = L2 ->Next = NULL;
	List head = (List)malloc(sizeof(struct Node));
	List rear = head;
	while(p && q ) {
		if(p->Data <= q->Data) {
			rear->Next = p;
			rear = p;
			p = p->Next;
		} else {
			rear->Next = q;
			rear = q;
			q = q->Next;
		}
	}
	if(p != NULL) {
		rear->Next = p;
	}
	if(q != NULL) {
		rear->Next = q;
	}
	return head;
}
