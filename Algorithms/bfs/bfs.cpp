#include<iostream>
#include<stdlib.h>
using namespace std;

int a[10000][4];
int main()
{
	int n, m;
	n = 6; m = 3;
	int head = -1;
	int tail = 0;
	int *t = new int[n];
	t[0] = 2; t[1] = 3; t[2] = 4; t[3] = 2; t[4] = 6; t[5] = 7;
	while (a[head][0] != n)
	{
		cout << tail << "   " << head << "   " << a[head][0] << endl;
		int a_head_0 = a[head][0];
		a[tail][0] = a_head_0 + 1;
		a[tail][1] = a[head][1];
		a[tail][2] = a[head][2];
		a[tail][3] = a[head][3];
		a[tail][1] += t[a[head][0]];
		tail++;
		a[tail][0] = a_head_0 + 1;
		a[tail][1] = a[head][1];
		a[tail][2] = a[head][2];
		a[tail][3] = a[head][3];
		a[tail][2] += t[a[head][0]];
		tail++;
		a[tail][0] = a_head_0 + 1;
		a[tail][1] = a[head][1];
		a[tail][2] = a[head][2];
		a[tail][3] = a[head][3];
		a[tail][3] += t[a[head][0]];
		tail++;
		head++;
	}
	int best;
	int best_endtime=999999;
	while (head < tail)
	{
		//cout << head;
		int endtime = 0;
		for (int i = 1; i <= m; i++)
		{
			if (a[head][i] > endtime)
			{
				endtime = a[head][i];
			}
		}
		if (endtime < best_endtime)
		{
			best_endtime = endtime;
			best = head;
		}
		head++;
	}
	cout << "best = " << best << endl;
	cout << "best_endtime = " << best_endtime << endl;
	system("pause");
	return 0;
}