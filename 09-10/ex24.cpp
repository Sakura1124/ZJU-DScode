/************************************************************************
*   文件名：ex24.cpp
*   文件描述：
    排序
*   创建人： Sakura, 2020-05-01  09:35
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<algorithm>
using namespace std;

typedef int ElementType;
void Bubble_Sort(ElementType A[], int N)
{
    int flag;
    for (int P = N - 1; P >= 0; P--)
    {
        flag = 0;
        for (int i = 0; i < P; i++)
        { /* 一趟冒泡*/
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                flag = 1; /* 标识发生了交换*/
            }
        }
        if (flag == 0)
            break; /* 全程无交换*/
    }
}
void Insert_Sort(ElementType A[], int N)
{ /* 插入排序 */
    int P, i;
    ElementType Tmp;

    for (P = 1; P < N; P++)
    {
        Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
        for (i = P; i > 0 && A[i - 1] > Tmp; i--)
            A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移*/
        A[i] = Tmp;          /* 放进合适的位置 */
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Insert_Sort(a, n);
    for (int i = 0; i < n; i++)
    {
        if(i!=0) cout <<" ";
        cout << a[i];
    }
    return 0;
}
