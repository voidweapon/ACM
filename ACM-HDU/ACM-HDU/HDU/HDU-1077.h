#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
#define  HDU_DEBUG
namespace HDU
{
	namespace HDU1077
	{
		/*
			半径为R的圆最多能覆盖多少点
			每个点做半径R的圆，在圆的交集中，找到最多重叠几次（圆交）
			寻找重叠：将所有相交弧的开始角度和结束角度排序（区间重叠）
			-|sa-----|sb----|ea------|eb---------------------

			-|sa-----|sb----|eb------|ea---------------------

			-|sa-----|ea----------|eb---------------------
				     |sb
		*/
#ifdef HDU_DEBUG
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1077.txt");
#endif // HDU_DEBUG
		extern void HDU_1077();
		struct PolarAngle
		{
			float angle;
			bool  istart;
		};
		float fishPoints[300][2];
		PolarAngle angles[300];
		float Distance(float x1, float y1, float x2, float y2)
		{
			float dx = x1 - x2;
			float dy = y1 - y2;
			return sqrt(dx*dx + dy*dy);
		}
		bool sort_func(PolarAngle a, PolarAngle b)
		{
			if (a.angle == b.angle)
				return a.istart > b.istart;
			else
				return a.angle < b.angle;
		}

		int hud_1007_fun(int n, float r)
		{
			float R = (2 * r);
			int m = 0;
			float radiusAngle = 0;
			float angle = 0;
			float dis = 0;
			int count = 0;
			int maxOverLap = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> fishPoints[i][0] >> fishPoints[i][1];
			}
			for (int i = 0; i < n; i++)
			{
				m = 0;
				count = 0;
				for (int j = 0; j < n; j++)
				{
					if (i == j) continue;

					dis = Distance(fishPoints[i][0], fishPoints[i][1], fishPoints[j][0], fishPoints[j][1]);
					if (dis <= R)
					{
						//计算相交弧的开始&结束角度
						radiusAngle = acos((dis / 2.0f) / r);
						angle = atan2(fishPoints[i][1] - fishPoints[j][1], fishPoints[i][0] - fishPoints[j][0]);
						angles[m].angle = angle - radiusAngle;
						angles[m].istart = true;
						m++;
						angles[m].angle = angle + radiusAngle;
						angles[m].istart = false;
						m++;
					}
				}
				//开始角度优先，角度越小越优先
				sort(angles, angles + m, sort_func);

				//求弧的重叠数量
				for (int h = 0; h < m; h++)
				{
					if (angles[h].istart)
					{
						count++;
						maxOverLap = (maxOverLap >= count) ? maxOverLap : count;
					}
					else
					{
						count--;
					}
				}
			}

			return maxOverLap + 1;
		}

		void HDU_1077()
		{
			int T, N;
			cin >> T;
			for (int i = 0; i < T; i++)
			{
				cin >> N;
				int count = hud_1007_fun(N, 1.0f);
				cout << count << endl;
			}
		}
	}
}
