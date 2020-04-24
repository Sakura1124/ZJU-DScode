/************************************************************************
*   文件名：ex4.cpp
*   文件描述：反转链表
	
*   创建人： Sakura, 2020-04-22
*   版本号：1.0
*   修改记录：
*	1.75行第一次反转放到循环外面，否则会超时
************************************************************************/
#include <iostream>
#include<iomanip>
using namespace std;


struct node
{
	int data;
	int next;
};
inline int lreverse(int head, int k, struct node link[])
{
    int cnt = 1, tmp;
	int now = head;
    int old = link[now].next;
    while(cnt < k)
    {
        tmp = link[old].next;
        link[old].next = now;
        now = old;
        old = tmp;
        cnt++;
    }
    link[head].next = old;
    return now;   
}
void print(int head, struct node link[])
{
	int p = head;
	while(p!=-1)
	{		
		cout<<setw(5) << setfill('0')<<p <<" "<<link[p].data<<" ";
		if(link[p].next >= 0) cout <<setw(5) << setfill('0')<<link[p].next <<endl;
		else cout<< link[p].next <<endl;		
		p = link[p].next;
	}
}

int size(int head, struct node link[])
{
	int cnt = 0, p = head;
	while (p!=-1)
	{
		cnt++;
		p = link[p].next;
	}
	return cnt;
	
}
int main()
{
	int n, k, head, cnt, index, flag = 1, tmp;
	struct node link[100000];
	cin >> head >> n >> k;
	while (n--)
	{
		cin >> index;
		cin >> link[index].data >> link[index].next;
	}
	n = size(head, link);
	cnt = n/k;
	int p = head;
	head = lreverse(p, k, link);
	cnt--;
	while (cnt--)
	{
		/*if(flag){
			head = lreverse(p, k, link);
			flag = 0;
		}else{*/
			tmp = link[p].next;			
			link[p].next = lreverse(tmp, k, link);
			p = tmp;
		//}
	}
	print(head, link);			
	return 0;
}
