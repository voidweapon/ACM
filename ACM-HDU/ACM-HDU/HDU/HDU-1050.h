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
	namespace HDU1050
	{
		/*
			δͨ��������
			�ƶ�����ʱ���ȵ�����ص����� = ���ٵ��ƶ�����
			��Ϊ�ص��ĵط��޷�ͨ�������Ⱥ����������
		*/
#ifdef DEBUG
		ifstream cin("./TestData/hdu1050.txt");
#endif

		int T, N;
		int r_min, r_max;
		int from, to;
		int moveingRoom[401];
		int maxCross;

		extern void HDU_1050();

		void HDU_1050()
		{
			int count = 0;
			cin >> T;
			while (T--)
			{
				cin >> N;
				memset(moveingRoom, 0, sizeof(moveingRoom));
				maxCross = 0;
				for (int i = 0; i < N; i++)
				{
					cin >> from >> to;
					r_min = MIN(from, to);
					r_max = MAX(from, to);
					for (int room = r_min; room <= r_max; room++)
					{
						moveingRoom[room]++;
						if (maxCross <= moveingRoom[room]) maxCross = moveingRoom[room];
					}
				}
				cout << maxCross * 10 <<endl;
			}
		}
	}
}