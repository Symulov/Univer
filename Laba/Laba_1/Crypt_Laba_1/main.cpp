#include <iostream>
#include <ctime>
#include <conio.h>
#include "windows.h"
#include "my_rand.h"
#include "Person.cpp"

using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");
	Person Alice, Bob;

	cout << "\n    Лабораторная работа №1 - ""Протокол Диффи-Хеллмана""\n\n";

	cout << "  Задача состоит в том, чтобы выбрать общий секретный ключ,\n";
	cout << " используя незащищенный от прослушивания канал связи.";

	cout << "\n\nАлиса задает два числа p и g:";
	Alice.setParam();
	cout << "\n\tp = " << Alice.p << "\n\tg = " << Alice.g;
	cout << "\nАлиса генерирет закрытый ключ:";
	cout << "\n\tprivateKey = " << Alice.showPrivateKey();
	cout << "\nАлиса вычисляет публичный ключ ( g^privateKey(mod p) ):";
	Alice.setOpenKey();
	cout << "\n\tpublicKey = " << Alice.publicKey;
	_getch();
	cout << "\n\nАлиса --------(p, g, publicKey)-------> Боб";
	Bob.p = Alice.p;
	Bob.g = Alice.g;
	Bob.partnerKey = Alice.publicKey;
	_getch();
	cout << "\n\nБоб генерирет закрытый ключ:";
	Bob.genPrivateKey();
	cout << "\n\tprivateKey = " << Bob.showPrivateKey();
	cout << "\nБоб вычисляет публичный ключ ( g^privateKey(mod p) ):";
	Bob.setOpenKey();
	cout << "\n\tpublicKey = " << Bob.publicKey;
	_getch();
	cout << "\n\nАлиса <-------(publicKey)-------- Боб";
	Alice.partnerKey = Bob.publicKey;
	_getch();
	cout << "\n\n\nЗаключительный этап:\n";
	cout << "\nАлиса на основе privateKey и полученного partnerKey вычисляет K:";
	Alice.setK();
	cout << "\n\tK = partnerKey^privateKey(mod p) = " << Alice.partnerKey << "^" << Alice.showPrivateKey() << "(mod " << Alice.p << ") = " << Alice.showK();
	_getch();
	cout << "\nБоб на основе privateKey и полученного partnerKey вычисляет K:";
	Bob.setK();
	cout << "\n\tK = partnerKey^privateKey(mod p) = " << Bob.partnerKey << "^" << Bob.showPrivateKey() << "(mod " << Bob.p << ") = " << Bob.showK();
	_getch();
	cout << "\n\n\nЗаключение:\nКак видим, в результате выполнения алгоритма, у Алисы и Боба есть общий секретный ключ.";

	cout << "\n\n";
	system("pause");
}