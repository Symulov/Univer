#include "my_rand.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const long long A = 23;
const long long C = 17;
const long long B = 999999;

long long gen_number()
{
	long long gamma = rand() % 999999;
	long long rez;
	rez = A * gamma + C;
	rez = rez % B;
	return rez;
}

bool checkPrime(long long a)
{
	for (long long i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}

long long gen_prime()
{
	while (true)
	{
		long long a = gen_number();
		if (checkPrime(a))
		{
			long long b = (a - 1) / 2;
			if (checkPrime(b))
				return a;
		}
	}
}

long long powmod(long long a, long long b, long long p)
{
	long long res = 1;
	while (b)
		if (b & 1)
			res = int(res * 1ll * a % p), --b;
		else
			a = int(a * 1ll * a % p), b >>= 1;
	return res;
}

long long generator(long long p)
{
	vector<long long> fact;
	long long phi = p - 1, n = phi;
	for (long long i = 2; i*i <= n; ++i)
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back(n);

	for (long long res = 2; res <= p; ++res) {
		bool ok = true;
		for (size_t i = 0; i<fact.size() && ok; ++i)
			ok &= powmod(res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}