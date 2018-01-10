// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string> 


using namespace std;

int gcd(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

// Function returns 1 if such element doesn't exist and 0 if exists and puts it
// in result.
int multInverse(int a, int N) {
	int x, y, d;
	d = gcd(a, N, x, y);
	if (d != 1) {
		return 1;
	}
	else {
		x = (x % N + N) % N;
		return x;
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

void addInverse(_int64 *r, _int64* m) {
	
	*r = *m + *r;
}


int main()

{
	int lcg[10];
	_int64 newLGC[5];
	
	ifstream fin;
	fin.open("1");
	
	for (int i = 0; i < 10;i++) {
		
		fin >> lcg[i];
		cout << lcg[i] << endl;
	}
		
	fin.close();
	system("pause");
		
	//lcg[0] = 228769;
	//lcg[1] = 189300;
	//lcg[2] = 522373;
	//lcg[3] = 714432;
	//lcg[4] = 56329;
	//lcg[5] = 716780;
	//lcg[6] = 23213;
	//lcg[7] = 44152;
	//lcg[8] = 503089;
	//lcg[9] = 437860;
	


	
	_int64 m = 4000000;
	_int64 multiplier = 0;
	_int64 increment = 0;
	

	while (m != 10000000)
	{	
		_int64 additive = lcg[1] - lcg[0];
		cout << m <<" - m" << endl;
		if (additive < 0) {
		
			addInverse(&additive, &m);
			cout << additive <<" - after additive" << endl;

		}
		long int inv = multInverse(additive, m);
		cout << inv << " - mult inverse" << endl;
		

		if (inv != 1) { //если инверсия существует


			_int64 multiplier = ((lcg[2] - lcg[1]) * inv) % m;
			if (multiplier < 0) {
				addInverse(&multiplier,&m); 
			}

			cout << multiplier << " - a" << endl;

			

			
			_int64  increment = ((lcg[1] - lcg[0] * multiplier) % m);
			addInverse(&increment, &m);
			cout << increment << " - c" << endl;
			

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
				system("pause");

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

