#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
namespace HDU
{
	namespace HDU1016
	{
		/*
			简单的深度搜索题目(DFS)
			提前打出素数表，加快素数判断

		*/

		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1016.txt");

		bool visited[21];
		int prime[40] = { 0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0 };
		int n;
		int circleNumber[21];

		extern void HDU_1016();

		bool isPrime(int number)
		{
			return prime[number] == 1;
		}

		void DFS(int num)
		{
			if (num == n && isPrime(circleNumber[num] + circleNumber[1]))
			{
				for (int i = 1; i < n; i++)
				{
					cout << circleNumber[i] << " ";
				}
				cout << circleNumber[n] << endl;
			}

			for (int i = 2; i <=n; i++)
			{
				if (!visited[i] && isPrime(circleNumber[num] + i))
				{
					visited[i] = true;
					circleNumber[num + 1] = i;
					DFS(num + 1);
					visited[i] = false;
				}
			}
		}

		void HDU_1016()
		{
			int count = 0;
			while (cin>> n)
			{
				memset(visited, false, sizeof(visited));
				visited[1] = true;
				circleNumber[1] = 1;
				count++;

				cout << "Case " << count << ":" << endl;
				DFS(1);
				cout << endl;
			}
		}
	}
}