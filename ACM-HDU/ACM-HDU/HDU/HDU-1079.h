#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

namespace HDU
{
	namespace HDU1079
	{
		/*
		
		*/
		ifstream cin("E:\\Vidweapon\\GitHub\\ACM\\ACM-HDU\\ACM-HDU\\TestData\\hdu1079.txt");

		extern void HDU_1079();
		map<int, bool> leapYears;
		//					 1  2   3   4	5	6	7	8	9	10	11	12
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int SG[102][13][32];


		bool LeapYear(int year)
		{
			return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}
		bool dateIsInvalid(int year, int month, int day)
		{
			bool isLeapYear = leapYears.find(year) != leapYears.end();
			if (year > 2001 || (year == 2001 && month > 11) || (year == 2001 && month == 11 && day >= 4))
				return true;

			if (month == 2 && isLeapYear)
				return day > 29;
			else
				return day > days[month];
		}

		int Func(int year, int month, int day)
		{
			if (SG[year - 1900][month][day] != -1) 
			{
				return SG[year - 1900][month][day];
			} 

			//
			if (year > 2001 || (year == 2001 && month > 11) || (year == 2001 && month == 11 && day >= 4))
			{
				SG[year - 1900][month][day] = 0;
				return 0;
			}

			bool isLeapYear = leapYears.find(year) != leapYears.end();
			int d = 0;
			int c1, c2;
			if (month < 12)
			{
				d = (isLeapYear && month == 2) ? 29 : days[month];
				//next day
				if (day == d)
				{
					c1 = Func(year, month + 1, 1);
				}
				else
					c1 = Func(year, month , day + 1);

				//next month
				if (!dateIsInvalid(year, month + 1, day))
				{
					c2 = Func(year, month + 1, day);
					if(c1== 0 || c2 == 0)
						SG[year - 1900][month][day] = 1;
					else if(c1==1 && c2 == 1)
						SG[year - 1900][month][day] = 0;
				}
				else
				{
					if (c1 == 0)
						SG[year - 1900][month][day] = 1;
					else
						SG[year - 1900][month][day] = 0;
				}
			}
			else
			{
				//next month
				c1 = Func(year + 1, 1, day);
				//next day
				if (day == days[month])
				{
					c2 = Func(year + 1, 1, 1);	
				}
				else
				{
					c2 = Func(year , month, day + 1);
				}

				if (c1 == 1 && c2 == 1)
					SG[year - 1900][month][day] = 0;
				else
					SG[year - 1900][month][day] = 1;
			}

			return SG[year - 1900][month][day];
		}
		void HDU_1079()
		{
			int T;
			int year, month, day;
			year = month = day = 0;
			memset(SG, -1, sizeof(SG));

			for (int i = 1900; i <= 2001; i++)
			{
				if (LeapYear(i))
					leapYears[i] = true;
			}

			cin >> T;
			for (int i = 0; i < T; i++)
			{
				cin >> year >> month >> day;
				Func(year, month, day);
				if (Func(year, month, day) == 1) 
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
}
