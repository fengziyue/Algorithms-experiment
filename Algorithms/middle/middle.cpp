// middle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
int a[100];
using namespace std;
int partition(int left, int right);
int selec(int left, int right, int k);
int main()
{
	for (int i = 0; i < 100; i++)
	{
		a[i] = i + 1;
	}

	cout << a[selec(0, 9, 5)] << endl;
	system("pause");
    return 0;
}
int partition(int left, int right)
{
	int l = left;
	int r = right;
	for (int i = l; i < r + 1; i++)
	{
		cout << a[i];
	}

	int pivot = a[left];
	while (left < right)
	{
		while(left < right && a[right] >= pivot)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right && a[left] <= pivot)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = pivot;
	cout << "par";
	for (int i = l; i < r + 1; i++)
	{
		cout << a[i];
	}
	cout << " ";
	cout << left;
	cout << endl;
	return left;
}
int middle_in_5(int left, int right)
{
	int temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = left; j < (right - i); j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	return left + 2;
}
int selec(int left, int right, int k)
{
	cout << "selec";
	for (int i = left; i < right + 1; i++)
	{
		cout << a[i];
	}
	cout << " " << k;
	cout << endl;
	if (k == 1)
	{
		int min = 999999999;
		int min_posi;
		for (int i = left; i < right + 1; i++)
		{
			if(a[i]<min)
			{
				min = a[i];
				min_posi = i;
			}
		}
		return min_posi;
	}
	if (k == (right - left + 1))
	{
		int max = -999999999;
		int max_posi;
		for (int i = left; i < right + 1; i++)
		{
			if (a[i]>max)
			{
				max = a[i];
				max_posi = i;
			}
		}
		return max_posi;
	}
	int n_num = right - left + 1;
	int n_group = n_num / 5;
	int n_last = n_num % 5;
	for (int i = 0; i < n_group; i++)
	{
		int m_in_5, temp;
		m_in_5 = middle_in_5(left + (5 * i), left + (5 * i) + 4);
		temp = a[m_in_5];
		a[m_in_5] = a[left + i];
		a[left + i] = temp;
	}
	if (n_last != 0)
	{
		int temp = a[n_group + left];
		a[n_group + left] = a[right];
		a[right] = temp;
		n_group++;
	}
	int pivot = selec(left, left + n_group - 1, (n_group/2)+1);
	int temp = a[left];
	a[left] = a[pivot];
	a[pivot] = temp;
	pivot = partition(left, right);
	if ((pivot + 1 - left) == k)
	{
		return pivot;
	}
	if ((pivot + 1 - left) < k)
	{
		cout << pivot << right;
		return selec(pivot + 1, right, k + left - 1 - pivot);
	}
	if ((pivot + 1 - left) > k)
	{
		return selec(left, pivot-1, k);
	}
}
