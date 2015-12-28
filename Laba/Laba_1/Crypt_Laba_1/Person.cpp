#include "my_rand.h"

class Person
{
private:
	long long privateKey, K;
public:
	long long p, g, publicKey, partnerKey;

	void setParam()// ��������� ���������� �����
	{
		p = gen_prime();
		g = generator(p);
		privateKey = gen_number();
	}
	void genPrivateKey()// ��������� ��������� ����� ����
	{
		privateKey = gen_number();
	}
	
	void setOpenKey()
	{
		publicKey = powmod(g, privateKey, p);
	}
	void setK()
	{
		K = powmod(partnerKey, privateKey, p);
	}

	long long showPrivateKey()
	{
		return privateKey;
	}
	long long showK()
	{
		return K;
	}
};