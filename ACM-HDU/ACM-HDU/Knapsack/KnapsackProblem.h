#pragma once
namespace KnapsackProblem
{
#define MAX(A, B) (A) > (B) ? (A) : (B)

#define N 100
#define V 100

//int f[V];

	/*01����
	 ������ı�������
	 
	 ������:f[i,v]��ʾ ǰi����Ʒ����һ�������ı������Ի�õļ�ֵ
	 ״̬ת�Ʒ���: f[i, v] = max(f[i-1, v], f[i-1, v-c[i]] + w[i])

	 ��i����Ʒ

	 for i=1..N
	   for v=c[i]..V
			f[i, v] = max{ f[i - 1, v], f[i - 1, v - c[i]] + w[i]}

	�ռ��Ż�
	for i=1..N
		for v=V..c[i]
			f[v] = max{ f[v], f[v - c[i]] + w[i]}

	��ʼ����ϸ��
	1.Ҫ��ǡ��װ������ f[0]=0, f[1..V] = -��
	2.��Ҫ��װ�� f[0..V] = 0
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