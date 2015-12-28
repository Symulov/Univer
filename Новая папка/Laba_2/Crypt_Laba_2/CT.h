#pragma once
#include "my_rand.h"

class CT
{
private:
	long long p, q;
public:
	long long v, n;

	void setParam(long long _p, long long _q)
	{
		p = _p;
		q = _q;
		n = p * q;
	}

	void setParam()
	{
		p = gen_prime();
		q = gen_prime();
		n = p * q;
	}
};
