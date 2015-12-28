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
		cout << "Протокол Фиата-Шамира\n";
		cout << "\n1) Демонстрационный пример с Wikipedia;";
		cout << "\n2) Выполнение лабораторной работы;";
		cout << "\n3) Выход;";
		cout << "\n---------------------------------\nВыберите пункт меню: ";
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