#pragma once
#include <iostream>
#include <fstream>
using namespace std;
namespace HDU
{
	namespace HDU1072
	{
#define  inf 0x3fffffff  
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1072.txt");
		extern void HDU_1072();

		int N, M;
		int MazeMap[9][9];
		bool visited[9][9];
		int steps[9][9];
		int times[9][9];
		int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0, 1 } };
		int curX, curY;
		int doorX, doorY;
		int breX, breY;
		int minStep;

		bool areaIsInvalid(int x, int y)
		{
			return x < 0 || x >= N || y < 0 || y >= M
				|| MazeMap[x][y] == 0;
		}


		void DFS(int x, int y, int step)
		{
			if (times[x][y] == 0) return;
			if (x == doorX && y == doorY)
			{
				if (step < minStep)
					minStep = step;
				return;
			}
			int newX, newY;

			for (int j = 0; j < 4; j++)
			{
				newX = dir[j][0] + x, newY = dir[j][1] + y;
				if (!areaIsInvalid(newX, newY))
				{
					//如果下一个格子已经走过，且剩余时间 
					if (visited[newX][newY] && steps[newX][newY] <= steps[x][y] && times[newX][newY] > times[x][y] - 1) continue;

					visited[newX][newY] = true;
					steps[newX][newY] = steps[x][y] + 1;
					times[newX][newY] = times[x][y] - 1;

					if (MazeMap[newX][newY] == 4 && times[newX][newY] > 0)
					{
						times[newX][newY] = 6;
					}
					DFS(newX, newY, step + 1);
				}
			}
		}


		void MakeMaze(int n, int m)
		{
			memset(MazeMap, -1, sizeof(MazeMap));
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < m; y++)
				{
					cin >> MazeMap[x][y];
					if (MazeMap[x][y] == 2)
						curX = x, curY = y;
					else if (MazeMap[x][y] == 3)
						doorX = x, doorY = y;
					else if (MazeMap[x][y] == 4)
						breX = x, breY = y;
				}
			}
		}

		void HDU_1072()
		{
			int T;
			cin >> T;
			for (int i = 0; i < T; i++)
			{
				cin >> N >> M;

				MakeMaze(N, M);
				memset(visited, false, sizeof(visited));
				memset(steps, 0, sizeof(steps));
				memset(times, 0, sizeof(times));
				visited[curX][curY] = true;
				times[curX][curY] = 6;

				minStep = inf;
				DFS(curX, curY, 0);
				if (minStep == inf)
					cout << -1 << endl;
				else
					cout << minStep << endl;
			}
		}
	}
}