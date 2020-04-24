/************************************************************************
*   文件名：ex5.cpp
*   文件描述：判断序列是否为出栈序列

    参考：https://github.com/lynnprosper/ZJU_MOOC_DS

*   创建人： Sakura, 2020-04-23  10:52-13.10
*   版本号：1.0
*   修改记录：
************************************************************************/
#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int m, n, k;
    stack<int> st;
    cin >> m >> n >> k;
	int flag[n];

	int t, num;
	for ( int i = 0; i < k; i++)
	{
		t = flag[i] = 1;
		for ( int j = 0; j < n; j++)
		{
			cin >> num;
			if (flag[i])
			{
				while (st.empty() || st.top() != num)	//比num小的数入栈
				{
					st.push(t);
					t++;
					if (st.size() > m)
					{
						flag[i] = 0;
						break;
					}
				}
			}
			if (flag[i] && !st.empty() && st.top() == num)  //弹出与输入序列匹配的数字
				st.pop();
		}
		while (!st.empty())		// 清空栈
			st.pop();
	}
	for (int i = 0; i < k; i++)
	{
		if (flag[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
