#pragma once
#include <iostream>
#include <fstream> 
#include <queue>
using namespace std;
namespace HDU
{
	namespace HDU1027
	{
		/*
			给定1-N的数，求从小到大排序的第M个序列。
			1.全排列
			2.搜索
			3.康托逆展开

			1<=N<=1000, 1<=M<=10000 : M < 8! 所以只需要求8阶
		*/
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1027.txt");
		extern void HDU_1027();

		int a[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
		int visited[1002];
		int N, M;
		int k, model;
		int count;

		void UnCantor(int m)
		{
			int step = 1;
			m = m - 1;

			while (step < N)
			{
				if (N - step <= 8)
				{
					k = m / a[N - step];
					model = m % a[N - step];
					count = 0;
					for (int i = 1; i <= N; i++)
					{
						if (!visited[i]) count++;
						if ((count - 1) == k)
						{
							cout << i << " ";
							visited[i] = 1;
							break;
						}
					}
					m = model;
				}
				else
				{
					for (int i = 1; i <= N; i++)
					{
						if (!visited[i])
						{
							cout << i << " ";
							visited[i] = 1;
							break;
						}
					}
				}

				step++;
			}
			for (int i = 1; i <= N; i++)
			{
				if (!visited[i])
				{
					cout << i <<endl;
				}
			}

		}

		void HDU_1027()
		{
			while (cin>>N>>M)
			{
				memset(visited, 0, sizeof(visited));
				UnCantor(M);
			}
		}
	}
}
