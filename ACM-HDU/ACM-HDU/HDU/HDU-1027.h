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
			����1-N���������С��������ĵ�M�����С�
			1.ȫ����
			2.����
			3.������չ��

			1<=N<=1000, 1<=M<=10000 : M < 8! ����ֻ��Ҫ��8��
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
