#pragma once
#include <iostream>
#include <fstream>
using namespace std;
namespace HDU
{
	namespace HDU1175
	{
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1175.txt");
		extern void HDU_1175();

		int N, M, q;
		int map[1003][1003];
		bool visited[1003][1003];
		int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1, 0 } };
		int sx, sy, ex, ey;


		bool isInvalidCell(int x, int y)
		{
			return x < 1 || x > N || y < 1 || y > M
				|| map[x][y] != 0 || visited[x][y] == true;
		}
		bool DFS(int x, int y, int cornerCount, int dirIndex)
		{
			int nx, ny;

			if (cornerCount > 2) return false;

			if (cornerCount <= 2 && x == ex && y == ey)
				return true;

			for (int i = 0; i < 4; i++)
			{
				nx = x + dir[i][0], ny = y + dir[i][1];
				if ((nx == ex && ny == ey) || !isInvalidCell(nx, ny))
				{
					visited[nx][ny] = true;
					if (dirIndex != i)
						cornerCount++;

					if (DFS(nx, ny, cornerCount, i)) return true;

					if (dirIndex != i)
						cornerCount--;
					visited[nx][ny] = false;
				}
			}

			return false;
		}

		void HDU_1175()
		{
			bool isPath = false;
			while (cin >> N >> M)
			{
				if (N == 0 && M == 0) return;

				memset(map, 0, sizeof(map));
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						cin >> map[i][j];
					}
				}
				cin >> q;
				for (int i = 0; i < q; i++)
				{
					isPath = false;
					memset(visited, false, sizeof(visited));
					cin >> sx >> sy >> ex >> ey;

					if (map[sx][sy] != map[ex][ey] || map[sx][sy] == 0)
					{
						cout << "NO" << endl;
					}
					else
					{
						isPath = DFS(sx, sy, -1, -1);
						if (isPath) cout << "YES" << endl;
						else cout << "NO" << endl;

					}
				}
			}
		}
	}

	namespace HDU1175_2 
	{
		//优化1：在拐角数==2时，判断当前各自到终点的方向，不在当前方向上则肯定到达不到。
		//优化2：
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1175.txt");
		extern void Solution();

		int N, M, q;
		int map[1003][1003];
		bool visited[1003][1003];
		int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1, 0 } };
		int sx, sy, ex, ey;

		bool isInvalidCell(int x, int y)
		{
			return x < 1 || x > N || y < 1 || y > M
				|| map[x][y] != 0 || visited[x][y] == true;
		}

		bool DFS(int x, int y, int cornerCount, int dirIndex)
		{
			int nx, ny;

			if (cornerCount > 2) return false;
			if (cornerCount <= 2 && x == ex && y == ey)
				return true;

			if (cornerCount == 2)
			{
				int dx, dy;
				dx = ex - x;
				dy = ey - y;

				if (dx != 0)
					dx /= abs(dx);
				if (dy)
					dy /= abs(dy);

				if (dx != dir[dirIndex][0] || dy != dir[dirIndex][1]) return false;
			}

			for (int i = 0; i < 4; i++)
			{
				nx = x + dir[i][0], ny = y + dir[i][1];
				if ((nx == ex && ny == ey) || !isInvalidCell(nx, ny))
				{
					visited[nx][ny] = true;
					if (dirIndex != i)
						cornerCount++;

					if (DFS(nx, ny, cornerCount, i)) return true;

					if (dirIndex != i)
						cornerCount--;
					visited[nx][ny] = false;
				}
			}

			return false;
		}

		void Solution()
		{
			bool isPath = false;
			while (cin >> N >> M)
			{
				if (N == 0 && M == 0) return;

				memset(map, 0, sizeof(map));
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= M; j++)
					{
						cin >> map[i][j];
					}
				}
				cin >> q;
				for (int i = 0; i < q; i++)
				{
					isPath = false;
					memset(visited, false, sizeof(visited));
					cin >> sx >> sy >> ex >> ey;

					if (map[sx][sy] != map[ex][ey] || map[sx][sy] == 0)
					{
						cout << "NO" << endl;
					}
					else
					{
						isPath = DFS(sx, sy, -1, -1);
						if (isPath) cout << "YES" << endl;
						else cout << "NO" << endl;
					}
				}
			}
		}
	}
}