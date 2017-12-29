// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>


using namespace std;

int gcdex(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d1 = gcdex(b, a % b, x1, y1);
	cout << d1 << endl;

	x = y1;
	cout << x << endl;
	y = x1 - (a / b) * y1;
	return d1;
}

// Function returns 1 if such element doesn't exist and 0 if exists and puts it
// in result.
int ReverseElement(int a, int N, int &result) {
	int x, y, d;
	d = gcdex(a, N, x, y);
	if (d != 1) {
		return 1;
	}
	else {
		result = x;
		return 0;
	}
}

long long int gcd(long long int a, long long int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void gen(long long int seed, long long int m_seed, _int64 mult,_int64 inc, _int64 *newLGC) {

	
	newLGC[0] = seed;
	

	for (int i = 1; i < 5; i++)
	{
		newLGC[i] = ((newLGC[i - 1] * mult) + inc) % m_seed;
	}



}


int main()

{
	_int64 lcg[10];
	_int64 newLGC[5];
	

	lcg[0] = 228769;
	lcg[1] = 189300;
	lcg[2] = 522373;
	lcg[3] = 714432;
	lcg[4] = 56329;
	lcg[5] = 716780;
	lcg[6] = 23213;
	lcg[7] = 44152;
	lcg[8] = 503089;
	lcg[9] = 437860;
	


	
	_int64 m = 1000000;
	_int64 multiplier = 0;
	_int64 increment = 0;

	int res = 11;
	while (m != 1004000)
	{
		long int inv = ReverseElement(abs(lcg[2] - lcg[1]), m,res);
		cout << res << endl;
		system("pause");

		if (inv != 1) { //если инверсия существует


			_int64 multiplier = ((lcg[3] - lcg[2]) * inv) % m;


			_int64  increment = abs(((lcg[2] - lcg[1]) * multiplier) % m);



			int first = lcg[0];
			int sec = lcg[1];
			int tri = lcg[2];
			int chet = lcg[3];

			_int64 sectest = ((multiplier * first) + increment) % m;
			_int64 tritest = ((multiplier * sec + increment)) % m;
			_int64 fourtest = ((multiplier * tri + increment)) % m;
			_int64 fivetest = ((multiplier * chet + increment)) % m;

			if (fourtest == lcg[3])
			{

				cout << m << " - m" << endl;
				cout << multiplier << " - a" << endl;
				cout << increment << " - c" << endl;


				cout << sectest << "  2" << endl;
				cout << tritest << "  3" << endl;
				cout << fourtest << "  4" << endl;
				gen(lcg[0], m, multiplier, increment,newLGC);


			}
			else {

				m = m + 1;
			}


		}
		else
		{
			m = m + 1;
		}


	}
	system("pause");

    return 0;
}

