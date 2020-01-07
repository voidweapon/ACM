#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
namespace HDU
{
	namespace HDU1010
	{
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1010.txt");

		extern void HDU_1010();
		int N, M, T;
		struct Pos
		{
			int x;
			int y;
			bool operator ==(Pos a)
			{
				return a.x == x && a.y == y;
			}
		};

		Pos dogPos, doorPos;
		int moveDef[4][2] = { {-1,0},{1,0},{0,-1}, {0, 1} };
		bool visited[8][8];
		int MazeMap[8][8];
		bool blockIsInvalid(int x, int y)
		{
			return x < 0 || x >= N || y < 0 || y >= M //edge
				|| MazeMap[x][y] == 1 || visited[x][y] == true;
		}

		bool DFS(int stepNumber)
		{
			if (stepNumber > T || (stepNumber != T && dogPos == doorPos)) return false;

			if (stepNumber == T && dogPos == doorPos) return true;

			for (int i = 0; i < 4; i++) 
			{
				dogPos.x += moveDef[i][0], dogPos.y += moveDef[i][1];
				if (!blockIsInvalid(dogPos.x, dogPos.y))
				{
					visited[dogPos.x][dogPos.y] = true;
					if (DFS(stepNumber + 1)) return true;
					visited[dogPos.x][dogPos.y] = false;
				}
				dogPos.x -= moveDef[i][0], dogPos.y -= moveDef[i][1];
			}

			return false;
		}

		void makeMaze(int n, int m)
		{
			char ch;
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < m; y++)
				{
					cin >> ch;
					switch (ch)
					{
					case '.':
						MazeMap[x][y] = 0;
						break;
					case 'X':
						MazeMap[x][y] = 1;
						break;
					case 'S':
						MazeMap[x][y] = 1;
						visited[x][y] = true;
						dogPos.x = x, dogPos.y = y;
						break;
					case 'D':
						MazeMap[x][y] = 0;
						doorPos.x = x, doorPos.y = y;
						break;

					default:
						break;
					}
				}
			}
		}

		void HDU_1010() 
		{	
			while (cin>>N>>M>>T)
			{
				if(N ==0 && M ==0 && T == 0)
					break;
				memset(visited, false, sizeof(visited));
				memset(MazeMap, -1, sizeof(MazeMap));

				makeMaze(N, M);
				if (abs(dogPos.x - doorPos.x) + abs(dogPos.y - doorPos.y) > T || (dogPos.x + doorPos.x + dogPos.y + doorPos.y + T) % 2 == 1)
				{
					cout << "NO" << endl;
				}
				else
				{
					bool isPath = DFS(0);
					if (isPath)
					{
						cout << "YES" << endl;
					}
					else
					{
						cout << "NO" << endl;
					}
				}
			}
		}
	}
}