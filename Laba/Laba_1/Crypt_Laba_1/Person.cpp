#include "my_rand.h"

class Person
{
private:
	long long privateKey, K;
public:
	long long p, g, publicKey, partnerKey;

	void setParam()// генерация параметров Алисы
	{
		p = gen_prime();
		g = generator(p);
		privateKey = gen_number();
	}
	void genPrivateKey()// генерация закрытого ключа Боба
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