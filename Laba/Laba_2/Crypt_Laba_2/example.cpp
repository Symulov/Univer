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
	cout << "������ ��������������� ������";
	cout << "\n\n����� ����� �������� ���� ������ ������� S\n\n";

	cout << "��������������� ��������:";
	cout << "\n\t���������� ����� T �������� � ��������� ������ n = p*q, ��� p, q - ������� � �������� � �������:";
	long long p = 683;
	long long q = 811;
	T.setParam(p, q);
	cout << "\n\t\tn = " << p << " * " << q << " = " << T.n;
	_getch();

	cout << "\n\n\t����� ����������� V = S^2 � �������������� � ���������� ������:";
	long long s = 43215;
	Alice.setS(s, T.n);
	T.v = Alice.v;
	cout << "\n\t\tV = " << s << "^2(mod " << T.n << ") = " << T.v;
	_getch();

	cout << "\n\n�������� ��������:";
	cout << "\n\t��������������� ����� ������� t, � ������� ������� ����� ������ �������� ������ ������� S:";
	int t = 1;
	cout << "\n\t\tt = " << t;
	cout << "\n\n\t�������������� ������ ������� (����������� t �������. ��������� ����������, ���� ��� ������ ������ �������):";
	for (int i = 0; i < t; i++)
	{
		cout << "\n\t\t" << i + 1 << "-��(��/��) �����:";
		Alice.r = 38177;
		Alice.getX(T.n);
		Bob.x = Alice.x;
		cout << "\n\t\t\t����� �������� r � ������� x = r^2, ����� ��������� ���������� x ����:";
		cout << "\n\t\t\t\tr = " << Alice.r << "\n\t\t\t\tx = " << Bob.x;
		_getch();

		cout << "\n\t\t\t��� �������� �������� ��� � � �������� ��� �����:";
		Bob.getE();
		Alice.e = Bob.e;
		cout << "\n\t\t\t\te = " << Alice.e;
		_getch();

		cout << "\n\t\t\t����� ��������� y = r*s^e � ���������� ��������� ����:";
		Alice.getY(T.n);
		Bob.y = Alice.y;
		cout << "\n\t\t\t\ty = " << Bob.y;
		_getch();

		cout << "\n\t\t\t��� ��������� �������������� y^2(mod n) == x*v^e(mod n):";
		Bob.y = powmod(Bob.y, 2, T.n);
		long long tmp = pow(T.v, Bob.e);
		tmp *= Bob.x;
		Bob.x = fmod(tmp, T.n);
		cout << "\n\t\t\t\ty^2 = " << Bob.y;
		cout << "\n\t\t\t\tx*v^e(mod n) = " << Bob.x;
		_getch();
		if (Bob.y == Bob.x)
			cout << "\n\n\t\t\t�������������� ������������!";
		else
			cout << "\n\n\t\t\t�������������� ���������!";
	}

	cout << "\n\n��� �������� � ������� ��� ������� ����� �������...";
	_getch();
}

void lab()
{
	system("cls");
	cout << "������������ ������";
	cout << "\n����� ����� �������� ���� ������ ������� S\n\n";
	int t;
	int check = 0;
	int k = 0;
	long long x;

	T.setParam();
	Alice.setS(T.n);
	T.v = Alice.v;	
	cout << "n = " << T.n << "\ns = " << Alice.showS() << "\nv = " << T.v;

	cout << "\n\n������� ����� ������� t = "; cin >> t;
	cout << "\n\t� ������ |     r     |       x       |  e  |     y     |     y^2     |     x*v^e    |   rez   |";
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
		cout << "\n\n\t����� ���������� ������ ������� S";
	if (k != t)
		cout << "\n\n\t��� �������� �������������� �����, �� �� ������� ���������� ������ ������� S";
	cout << "\n\n��� �������� � ������� ��� ������� ����� �������...";
	_getch();
}