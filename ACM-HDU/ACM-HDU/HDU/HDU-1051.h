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
			һ����֦���г��Ⱥ�����������֦�����Ⱥ��������������򡣲�������ʱ�ֶѼ�������
			�����ٵĶ���
			���Ȱ����Ȼ�����������Ȼ��������һ��ά�Ȱ�����ɸѡ�����ֶѵ�˳��Ϸ�������һ���ʣ�µ���֦��Ϊ�¶ѣ�����ɸѡָ����
			ֱ���������
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