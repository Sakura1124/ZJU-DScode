
/*
原地址
https://github.com/lynnprosper/ZJU_MOOC_DS

*/
#include <iostream>
#include <iomanip>

//key: use the array's labelcase as every data's local address;

#define N 100001
using namespace std;

int main()
{
	int data[N], next[N];
	int temp, n, k, st, i;
	cin >> st >> n >> k;

	i = 0;
	while (i < n)
	{
		cin >> temp;
		cin >> data[temp] >> next[temp];
		i++;
	}

	int adr[N], re[N];
	int cnt = 0;
	temp = st;
	while (temp != -1)		// find the address linklist;
	{	
		adr[cnt++] = temp;
		temp = next[temp];
	}

	for (i = 0; i < cnt; i++)	//copy it to re[];
		re[i] = adr[i];

	i = 0;
	while (k != 1 && i < cnt - cnt%k)
	{
		re[i] = adr[k - i%k - 1 + i / k * k];	// reverse the linklist;
		i++;
	}

	for (i = 0; i < cnt - 1; i++)		//output result;
		printf("%05d %d %05d\n", re[i], data[re[i]], re[i + 1]);
	printf("%05d %d -1\n", re[i], data[re[i]]);

	return 0;
}