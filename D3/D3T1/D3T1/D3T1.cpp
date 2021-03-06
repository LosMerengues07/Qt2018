// D3T1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <ctime>
using namespace std;

int main()
{
	int num_array[] = { 16,32,64,100,128,180,256,300,380,450,512 };
	for (int flag = 0; flag < 11; flag++)
	{
		int n = num_array[flag];
		cout << "N=" << n << endl;
		vector<vector<vector<int> > > a(n, vector<vector<int> >(n, vector<int>(n)));
		vector<vector<vector<int> > > b(n, vector<vector<int> >(n, vector<int>(n)));
		vector<vector<vector<int> > > c(n, vector<vector<int> >(n, vector<int>(n)));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					a[i][j][k] = j + k;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					b[i][j][k] = j;
				}
			}
		}

		//—————————以上为生成并初始化三维数组————————————//

/*
以下为测试代码，规定i,j,k分别代表最内层，次外层，和最外层
*/


		clock_t start, end;

		start = clock();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "i j k runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

		start = clock();
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < n; j++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "i k j runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

		start = clock();
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "k i j runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

		start = clock();
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int i = 0; i < n; i++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "k j i runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;


		start = clock();
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int k = 0; k < n; k++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "j i k runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

		start = clock();
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					c[i][j][k] = a[i][j][k] + b[i][j][k];
				}
			}
		}
		end = clock();
		cout << "j k i runtime=" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;

	}
	return 0;
}

