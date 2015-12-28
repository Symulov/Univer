#pragma once
#include "my_rand.h"

class Persons
{
private:
	long long s;

public:
	long long r, x, y, v;
	int e;

	void setS(long long _s, long long n)
	{
		s = _s;
		v = powmod(s, 2, n);
	}

	void setS(long long n)
	{
		s = gen_prime_NOD(n);
		v = powmod(s, 2, n);
	}

	void getX(long long n)
	{
		x = powmod(r, 2, n);
	}

	void getY(long long n)
	{
		y = fmod((r*pow(s, e)), n);
	}

	void getE()
	{
		int i = rand() % 10;
		if (i > 10 / 2)
			e = 1;
		else
			e = 0;
	}
	
	long long  showS()
	{
		return s;
	}
};
