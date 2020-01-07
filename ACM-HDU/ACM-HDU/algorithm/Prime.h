#pragma once
//素数判定


unsigned Montgomery(unsigned n, unsigned p, unsigned m)
{ // 快速计算 (n ^ e) % m 的值，与power算法极类似  费马小定理: N^(P-1)%P=1 or N^P%P=N
	unsigned r = n % m; // 这里的r可不能省  
	unsigned k = 1;
	while (p > 1)
	{
		if ((p & 1) != 0)
		{
			k = (k * r) % m; // 直接取模  
		}
		r = (r * r) % m; // 同上  
		p /= 2;
	}
	return (r * k) % m; // 还是同上  
}
unsigned Montgomery2(unsigned n, unsigned p, unsigned m)
{ //快速计算(n^p)%m的值  
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
		// 小于2的数即不是合数也不是素数  
		throw 0;
	}

	//预先设定的素数表越大，越准确
	static unsigned aPrimeList[] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,41,
		43, 47, 53, 59, 61,67, 71, 73, 79, 83, 89, 97
	};
	const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
	for (int i = 0; i < nListNum; ++i)
	{
		// 按照素数表中的数对当前素数进行判断  
		if (1 != Montgomery(aPrimeList[i], n - 1, n)) // 蒙格马利算法  
		{
			return false;
		}
	}
	return true;
}
