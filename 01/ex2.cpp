#include <stdio.h>

void MaxSubSeqSum4(int a[], int n) //复杂度为O(n);
{
    int start = 0, end = n - 1, tmp = 0, tmp2 = 0, flag = 1, flag2 = 1;
    int thisSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && flag == 1)
        { //找到第一个0
            flag = 0;
            tmp2 = i;
        }
        if (a[i] > 0) //判断是否为全0和负数
        {
            flag2 = 0;
        }
        thisSum += a[i];
        if (thisSum > maxSum)
        {
            start = tmp;
            maxSum = thisSum;
            end = i;
        }
        if (thisSum < 0)
        {
            thisSum = 0;
            tmp = i + 1;
        }
    }
    if(flag == 0 && flag2 == 1)//全为负数和0的情况
    {
        start = end =tmp2;
    }
    printf("%d %d %d", maxSum, a[start], a[end]);
    //return maxSum;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    MaxSubSeqSum4(a, n);
}