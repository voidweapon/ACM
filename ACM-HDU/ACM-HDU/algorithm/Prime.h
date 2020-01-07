#pragma once
//�����ж�


unsigned Montgomery(unsigned n, unsigned p, unsigned m)
{ // ���ټ��� (n ^ e) % m ��ֵ����power�㷨������  ����С����: N^(P-1)%P=1 or N^P%P=N
	unsigned r = n % m; // �����r�ɲ���ʡ  
	unsigned k = 1;
	while (p > 1)
	{
		if ((p & 1) != 0)
		{
			k = (k * r) % m; // ֱ��ȡģ  
		}
		r = (r * r) % m; // ͬ��  
		p /= 2;
	}
	return (r * k) % m; // ����ͬ��  
}
unsigned Montgomery2(unsigned n, unsigned p, unsigned m)
{ //���ټ���(n^p)%m��ֵ  
	unsigned k = 1;
	n %= m;
	while (p != 1)
	{
		if (0 != (p & 1))k = (k*n) % m;
		n = (n*n) % m;
		p >>= 1;
	}
	return(n*k) % m;
}

bool IsPrime3(unsigned n)
{
	if (n < 2)
	{
		// С��2���������Ǻ���Ҳ��������  
		throw 0;
	}

	//Ԥ���趨��������Խ��Խ׼ȷ
	static unsigned aPrimeList[] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,41,
		43, 47, 53, 59, 61,67, 71, 73, 79, 83, 89, 97
	};
	const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
	for (int i = 0; i < nListNum; ++i)
	{
		// �����������е����Ե�ǰ���������ж�  
		if (1 != Montgomery(aPrimeList[i], n - 1, n)) // �ɸ������㷨  
		{
			return false;
		}
	}
	return true;
}
