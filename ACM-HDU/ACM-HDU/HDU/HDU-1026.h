#pragma once
#include <iostream>
#include <fstream> 
#include <queue>
using namespace std;
namespace HDU
{
	namespace HDU1026 
	{
		/*
			使用优先队列让当前步数少的项优先出队列，从而保证每次处理时都是最短路径状态。
		*/
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1026.txt");
		extern void HDU_1026();
		int N, M;
		int mazeMap[100][100];
		bool visited[100][100];
		int path[100][100];
		int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0, 1 } };
		priority_queue<point> searchQueue;

		struct point
		{
			int x, y;
			int time;
			friend bool operator < (point a ,point b)
			{
				return a.time > b.time;
			}
		};

		bool areaIsInvalid(int x, int y)
		{
			return x < 0 || x >= N || y < 0 || y >= M
				|| mazeMap[x][y] == -1 || visited[x][y] == true;
		}

		int BFS()
		{
			point curent, next;
			curent.x = N - 1,curent.y = N - 1;
			curent.time = mazeMap[curent.x][curent.y];
			searchQueue.push(curent);
			visited[curent.x][curent.y] = true;

			while (!searchQueue.empty())
			{
				curent = searchQueue.top();
				searchQueue.pop();

				if (curent.x == 0 && curent.y == 0)
				{
					return curent.time;
				}

				for (int i = 0; i < 4; i++)
				{
					next.x = curent.x +  dir[i][0], next.y = curent.y + dir[i][1];
					if (areaIsInvalid(next.x, next.y)) continue;

					next.time = curent.time + 1 + mazeMap[next.x][next.y];
					visited[next.x][next.y] = true;
					path[next.x][next.y] = i;
					searchQueue.push(next);
				}
			}

			return -1;
		}

		void MakeMaze()
		{
			char ch;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cin >> ch;
					switch (ch)
					{
					case '.':
						mazeMap[i][j] = 0;
						break;
					case 'X':
						mazeMap[i][j] = -1;
						break;
					default:
						mazeMap[i][j] = ch - '0';
						break;
					}
				}
			}
		}

		void printPath(int step)
		{
			point curent, next;
			curent.x = 0, curent.y = 0;
			curent.time = mazeMap[curent.x][curent.y];
			int dirValue;
			int tiem = 1;

			printf("It takes %d seconds to reach the target position, let me show you the way.\n", step);
			while (!(curent.x == N - 1 && curent.y == M - 1 && curent.time == 0))
			{
				if (curent.time > 0)
				{
					printf("%ds:FIGHT AT (%d,%d)\n", tiem, curent.x, curent.y);
					curent.time--;
				}		
				else
				{
					dirValue = path[curent.x][curent.y];
					next.x = curent.x - dir[dirValue][0], next.y = curent.y - dir[dirValue][1];

					printf("%ds:(%d,%d)->(%d,%d)\n", tiem, curent.x, curent.y, next.x, next.y);

					curent = next;
					curent.time = mazeMap[curent.x][curent.y];
				}
				tiem++;
			}
		}

		void HDU_1026()
		{
			bool hasPath = false;
			int step;
			while (	cin>>N>>M )
			{
				memset(mazeMap, -1, sizeof(mazeMap));
				memset(path, -1, sizeof(path));
				memset(visited, false, sizeof(visited));
				while (!searchQueue.empty())
				{
					searchQueue.pop();
				}

				MakeMaze();
				step = BFS();

				if (step != -1)
					printPath(step);
				else
					printf("God please help our poor hero.\n");

				printf("FINISH\n");
			}
		}
	}
}