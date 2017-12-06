#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n, k;
	cout << "please input n and k" << endl;
	cin >> n >> k;
	int *a = new int[n+1];
	int *b = new int[n+1];
	cout << "please input n numbers" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = 1;
	}
	a[n] = -1;

	int cur_index = 0;
	while (k > 0)
	{
		int min_index = cur_index;
		int min = a[cur_index];
		for (int i = 0; i <= k; i++)
		{
			if (a[cur_index + i] < min)
			{
				min = a[cur_index + i];
				min_index = cur_index + i;
			}
		}
		for (int i = cur_index;i<min_index; i++)
		{
			b[i] = 0;
			k--;
		}
		cur_index = min_index + 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i])
			cout << a[i] << " ";
	}
	system("pause");
	return 0;
}