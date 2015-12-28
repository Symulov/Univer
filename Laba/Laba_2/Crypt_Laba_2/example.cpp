#include <iostream>
#include <conio.h>
#include "CT.h"
#include "Persons.h"
#include "my_rand.h"

using namespace std;

Persons Alice, Bob;
CT T;

void exp()
{
	system("cls");
	cout << "Выбран демонстационный пример";
	cout << "\n\nАлиса хочет доказать Бобу знание секрета S\n\n";

	cout << "Предварительные действия:";
	cout << "\n\tДоверенный центр T выбирает и публикует модуль n = p*q, где p, q - простые и держатся в секрете:";
	long long p = 683;
	long long q = 811;
	T.setParam(p, q);
	cout << "\n\t\tn = " << p << " * " << q << " = " << T.n;
	_getch();

	cout << "\n\n\tЗатем вычисляется V = S^2 и регистрируется в доверенном центре:";
	long long s = 43215;
	Alice.setS(s, T.n);
	T.v = Alice.v;
	cout << "\n\t\tV = " << s << "^2(mod " << T.n << ") = " << T.v;
	_getch();

	cout << "\n\nОсновыне действия:";
	cout << "\n\tУстанавливается число раундов t, в течение которых Алиса должна доказать знание секрета S:";
	int t = 1;
	cout << "\n\t\tt = " << t;
	cout << "\n\n\tДоказательство знания секрета (Выполняется t раундов. Считается доказанным, если все раунды прошли успешно):";
	for (int i = 0; i < t; i++)
	{
		cout << "\n\t\t" << i + 1 << "-ый(ой/ий) раунд:";
		Alice.r = 38177;
		Alice.getX(T.n);
		Bob.x = Alice.x;
		cout << "\n\t\t\tАлиса выбирает r и считает x = r^2, затем отправяет полученный x Бобу:";
		cout << "\n\t\t\t\tr = " << Alice.r << "\n\t\t\t\tx = " << Bob.x;
		_getch();

		cout << "\n\t\t\tБоб случайно выбирает бит е и отсылает его Алисе:";
		Bob.getE();
		Alice.e = Bob.e;
		cout << "\n\t\t\t\te = " << Alice.e;
		_getch();

		cout << "\n\t\t\tАлиса вычисляет y = r*s^e и отправляет результат Бобу:";
		Alice.getY(T.n);
		Bob.y = Alice.y;
		cout << "\n\t\t\t\ty = " << Bob.y;
		_getch();

		cout << "\n\t\t\tБоб проверяет доказательство y^2(mod n) == x*v^e(mod n):";
		Bob.y = powmod(Bob.y, 2, T.n);
		long long tmp = pow(T.v, Bob.e);
		tmp *= Bob.x;
		Bob.x = fmod(tmp, T.n);
		cout << "\n\t\t\t\ty^2 = " << Bob.y;
		cout << "\n\t\t\t\tx*v^e(mod n) = " << Bob.x;
		_getch();
		if (Bob.y == Bob.x)
			cout << "\n\n\t\t\tДоказательство подтеврждено!";
		else
			cout << "\n\n\t\t\tДоказательство отклонено!";
	}

	cout << "\n\nДля возврата в главное мею нажмите любую клавишу...";
	_getch();
}

void lab()
{
	system("cls");
	cout << "Лабораторная работа";
	cout << "\nАлиса хочет доказать Бобу знание секрета S\n\n";
	int t;
	int check = 0;
	int k = 0;
	long long x;

	T.setParam();
	Alice.setS(T.n);
	T.v = Alice.v;	
	cout << "n = " << T.n << "\ns = " << Alice.showS() << "\nv = " << T.v;

	cout << "\n\nВведите число раундов t = "; cin >> t;
	cout << "\n\t№ раунда |     r     |       x       |  e  |     y     |     y^2     |     x*v^e    |   rez   |";
	for (int i = 0; i < t; i++)
	{
		Alice.r = gen_prime_NOD(T.n);
		Alice.getX(T.n);
		Bob.x = Alice.x;
		Bob.getE();
		Alice.e = Bob.e;
		Alice.getY(T.n);
		Bob.y = Alice.y;
		long long y = powmod(Bob.y, 2, T.n);
		if (Alice.e == 1)
		{
			x = powmod(Bob.x*T.v, 1, T.n);
		}
		if (Alice.e == 0)
		{
			x = powmod(Bob.x, 1, T.n);
		}		
		if (y == x)
		{
			k++;
			check = 1;
		}
		if (y != x)
		{
			check = 0;
		}
		if (check == 1)
			cout << "\n\t    " << i + 1 << "\t     " << Alice.r << "\t" << Bob.x << "\t" << Alice.e << "    " << Bob.y << "\t  " << y << "\t " << x << "\t +";
		if (check == 0)
			cout << "\n\t    " << i + 1 << "\t     " << Alice.r << "\t" << Bob.x << "\t" << Alice.e << "    " << Bob.y << "\t  " << y << "\t " << x << "\t -";
	}

	if (k == t)
		cout << "\n\n\tАлиса подтведила знание секрета S";
	if (k != t)
		cout << "\n\n\tБоб опроверг доказательства Алисы, ей не удалось подтведить знание секрета S";
	cout << "\n\nДля возврата в главное мею нажмите любую клавишу...";
	_getch();
}