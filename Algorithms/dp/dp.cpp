// dp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
double cost[1000];
double value[1000];
int n, v;
struct point {
	double capacity;
	double worth;
	point(double a = 0, double b = 0) { capacity = a; worth = b; }
};
list<point> p;
list<point> q;
list<point> r;
void ptoq(int i)
{
	q.clear();
	list<point>::iterator it;
	double tempcap;
	double tempval;
	for (it = p.begin(); it != p.end(); ++it)
	{
		tempcap = (*it).capacity + cost[i];
		tempval = (*it).worth + value[i];
		point temp(tempcap, tempval);
		if (tempcap <= v)
			q.push_back(temp);
	}
}
void marriage()
{
	r.clear();
	list<point>::iterator itp, itq;
	itp = p.begin();
	itq = q.begin();
	while (itp != p.end() && itq != q.end())
	{
		if ((*itp).capacity>(*itq).capacity)
		{
			if (r.empty() || (*itq).worth>r.back().worth)
				r.push_back(*itq);
			itq++;
		}
		else if ((*itp).capacity<(*itq).capacity)
		{
			if (r.empty() || (*itp).worth>r.back().worth)
				r.push_back(*itp);
			itp++;
		}
		else
		{
			if ((*itp).worth>(*itq).worth)
			{
				if (r.empty() || (*itp).worth>r.back().worth)
					r.push_back(*itp);
			}
			else
			{
				if (r.empty() || (*itq).worth>r.back().worth)
					r.push_back(*itq);
			}
			itq++;
			itp++;
		}
	}
	while (itp != p.end())
	{
		if (r.empty() || (*itp).worth>r.back().worth)
			r.push_back(*itp);
		itp++;
	}
	while (itq != q.end())
	{
		if (r.empty() || (*itq).worth>r.back().worth)
			r.push_back(*itq);
		itq++;
	}
	p = r;
}
int main()
{
	int i;
	cout << "please input n and v:" << endl;
	cin >> n >> v;
	cout << "please input cost and value :" << endl;
	for (i = 1; i <= n; ++i)
		cin >> cost[i] >> value[i];
	point tmp(0, 0);
	p.push_back(tmp);
	ptoq(1);
	for (i = 2; i <= n; ++i)
	{
		marriage();
		ptoq(i);
	}
	marriage();
	printf("%lf", p.back().worth);
	system("pause");
	return 0;
}