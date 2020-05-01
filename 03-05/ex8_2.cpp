/************************************************************************
*   文件名：ex8_2.cpp
*   文件描述：
    参考：
    https://github.com/Daipuwei/ZJU-MOOC-DataStructure/tree/master/%E7%AC%AC%E4%B8%89%E5%91%A8

*   创建人： Sakura, 2020-04-24  11.23
*   版本号：1.0
*   修改记录：
************************************************************************/

#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
vector<int> pre, in, post, value;
void postorder(int root, int start, int end)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != pre[root])
        i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}
int main()
{
    int n;
    scanf("%d", &n);
    char str[5];
    stack<int> s;
    int key = 0;
    while (~scanf("%s", str))
    {
        if (strlen(str) == 4)
        { // Push
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key); //preorder
            s.push(key++);
        }
        else
        {
            in.push_back(s.top()); // inorder
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d", value[post[i]]);
    return 0;
}
/*
voidsolve(intpreL, intinL, intpostL, intn)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        post[postL] = pre[preL];
        return;
    }
    root = pre[preL];
    post[postL + n - 1] = root;
    for (i = 0; i < n; i++)
        if (in[inL + i] == root)
            break;
    L = i;
    R = n - L - 1;
    solve(preL + 1, inL, postL, L);
    solve(preL + L + 1, inL + L + 1, postL + L, R);
}
*/