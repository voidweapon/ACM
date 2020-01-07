#pragma once
#define DEBUG
#define MAX(a,b) (a) > (b) ? (a): (b)
#define MIN(a,b) (a) < (b) ? (a): (b)
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
namespace HDU
{
	namespace HDU1051
	{
		/*
			一堆树枝，有长度和重量，将树枝按长度和重量都增长排序。不能排序时分堆继续排序
			求最少的堆数
			首先按长度或者重量排序。然后再用另一个维度按增序筛选，保持堆的顺序合法。遍历一遍后，剩下的树枝作为新堆，继续筛选指导。
			直到排序完成
		*/
#ifdef DEBUG
		ifstream cin("./TestData/hdu1051.txt");
#endif

		extern void HDU_1051();

		typedef struct stick
		{
			int l;
			int w;
		} Stick;

		int cmp(Stick a, Stick b)
		{
			if (a.l == b.l)
			{
				return a.w < b.w;
			}
			else
			{
				return a.l < b.l;
			}
		}

		void HDU_1051()
		{
			int T, N;
			int i, j;
			Stick sticks[5000];
			int visited[5000];
			int step = 0;
			int sweepCount;
			cin >> T;
			while (T--)
			{
				cin >> N;
				sweepCount = 0;
				step = 0;
				memset(visited, 0, sizeof(visited));

				for (i = 0; i < N; i++)
				{
					cin >> sticks[i].l >> sticks[i].w;
				}
				sort(sticks, sticks + N, cmp);

				while (sweepCount != N)
				{
					j = -1;
					for (i = 0; i < N; i++)
					{
						if (visited[i]) continue;


						if (j == -1 || sticks[i].w >= sticks[j].w)
						{
							sweepCount++;
							visited[i] = 1;
							j = i;
						}
					}
					step++;
				}

				cout << step << endl;
			}
		}
	}
}