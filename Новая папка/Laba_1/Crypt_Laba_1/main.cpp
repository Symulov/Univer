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

	cout << "\n    ������������ ������ �1 - ""�������� �����-��������""\n\n";

	cout << "  ������ ������� � ���, ����� ������� ����� ��������� ����,\n";
	cout << " ��������� ������������ �� ������������� ����� �����.";

	cout << "\n\n����� ������ ��� ����� p � g:";
	Alice.setParam();
	cout << "\n\tp = " << Alice.p << "\n\tg = " << Alice.g;
	cout << "\n����� ��������� �������� ����:";
	cout << "\n\tprivateKey = " << Alice.showPrivateKey();
	cout << "\n����� ��������� ��������� ���� ( g^privateKey(mod p) ):";
	Alice.setOpenKey();
	cout << "\n\tpublicKey = " << Alice.publicKey;
	_getch();
	cout << "\n\n����� --------(p, g, publicKey)-------> ���";
	Bob.p = Alice.p;
	Bob.g = Alice.g;
	Bob.partnerKey = Alice.publicKey;
	_getch();
	cout << "\n\n��� ��������� �������� ����:";
	Bob.genPrivateKey();
	cout << "\n\tprivateKey = " << Bob.showPrivateKey();
	cout << "\n��� ��������� ��������� ���� ( g^privateKey(mod p) ):";
	Bob.setOpenKey();
	cout << "\n\tpublicKey = " << Bob.publicKey;
	_getch();
	cout << "\n\n����� <-------(publicKey)-------- ���";
	Alice.partnerKey = Bob.publicKey;
	_getch();
	cout << "\n\n\n�������������� ����:\n";
	cout << "\n����� �� ������ privateKey � ����������� partnerKey ��������� K:";
	Alice.setK();
	cout << "\n\tK = partnerKey^privateKey(mod p) = " << Alice.partnerKey << "^" << Alice.showPrivateKey() << "(mod " << Alice.p << ") = " << Alice.showK();
	_getch();
	cout << "\n��� �� ������ privateKey � ����������� partnerKey ��������� K:";
	Bob.setK();
	cout << "\n\tK = partnerKey^privateKey(mod p) = " << Bob.partnerKey << "^" << Bob.showPrivateKey() << "(mod " << Bob.p << ") = " << Bob.showK();
	_getch();
	cout << "\n\n\n����������:\n��� �����, � ���������� ���������� ���������, � ����� � ���� ���� ����� ��������� ����.";

	cout << "\n\n";
	system("pause");
}