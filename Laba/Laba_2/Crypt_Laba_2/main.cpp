#include <iostream>
#include <conio.h>
#include <ctime>
#include "example.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	int sw;
	while (true)
	{
		system("cls");
		cout << "�������� �����-������\n";
		cout << "\n1) ���������������� ������ � Wikipedia;";
		cout << "\n2) ���������� ������������ ������;";
		cout << "\n3) �����;";
		cout << "\n---------------------------------\n�������� ����� ����: ";
		sw = _getch();
		switch (sw)
		{
		case '1':
		{
			exp();
			break;
		}
		case '2':
		{
			lab();
			break;
		}
		case '3':
		{
			exit(0);
		}
		}
	}
}