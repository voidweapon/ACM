#pragma once
#define DEBUG

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
namespace HDU
{
	namespace HDU1059
	{
		/*
			´ò±í
		*/
#ifdef DEBUG
		ifstream cin("./TestData/hdu1059.txt");
#endif
		bool flag[120001];
		int values[6];
		int totalValue = 0;
		int average = 0;

		void DP()
		{
			int sum = 0;
			int piece = 1;
			int value = 0;
			flag[0] = true;
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j <= sum; j++)
				{
					if (flag[j])
					{
						for (int k = 0; k <= values[i]; k++)
						{
							value = j + piece * k;
							flag[value] = true;
							if (value >= average) break;
						}
					}
				}
				sum += (piece * values[i]);
				piece++;
			}
		}

		extern void HDU_1059();

		void HDU_1059()
		{
			bool endFlag = true;
			int caseIndex = 0;
			while (true)
			{
				memset(values, 0, sizeof(values));
				memset(flag, false, sizeof(flag));
				cin >> values[0] >> values[1] >> values[2] >> values[3] >> values[4] >> values[5];
				endFlag = true;
				totalValue = 0;
				caseIndex++;
				for (int i = 0; i < 6; i++)
				{
					if (values[i] != 0)
					{
						endFlag = false;
					}
					totalValue += (values[i] * (i + 1));
				}
				if (endFlag) return;
				cout << "Collection #" << caseIndex << ":" << endl;

				if (totalValue % 2 != 0) 
				{
					cout << "Can't be divided." << endl;
				}
				else
				{
					average = totalValue / 2;
					DP();
					if (flag[average])
					{
						cout << "Can be divided." << endl;
					}
					else
					{
						cout << "Can't be divided." << endl;
					}
				}
			}
		}
	}
}