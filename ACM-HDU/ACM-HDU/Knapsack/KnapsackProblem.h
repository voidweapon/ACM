#pragma once
namespace KnapsackProblem
{
#define MAX(A, B) (A) > (B) ? (A) : (B)

#define N 100
#define V 100

//int f[V];

	/*01背包
	 最基本的背包问题
	 
	 子问题:f[i,v]表示 前i件物品放人一个容量的背包可以获得的价值
	 状态转移方程: f[i, v] = max(f[i-1, v], f[i-1, v-c[i]] + w[i])

	 第i件物品

	 for i=1..N
	   for v=c[i]..V
			f[i, v] = max{ f[i - 1, v], f[i - 1, v - c[i]] + w[i]}

	空间优化
	for i=1..N
		for v=V..c[i]
			f[v] = max{ f[v], f[v - c[i]] + w[i]}

	初始化的细节
	1.要求恰好装满背包 f[0]=0, f[1..V] = -∞
	2.不要求装满 f[0..V] = 0
	*/
	void ZeroOneKnapsack(int *F,int cost, int weight)
	{
		int v = 1;
		for (v = V; v >= cost; v--)
		{
			F[v] = MAX(F[v], F[v - cost] + weight);
		}
	}

}