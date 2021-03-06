// 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Combi.h"
#include <iomanip> 
#include "salesman.h"

using namespace std;
#define N 10	//кол-во городов

double dget(double rmin, double rmax) // получить случайное число
{
	return ((double)rand() / (double)RAND_MAX)*(rmax - rmin) + rmin;
};

int iget(int rmin, int rmax)        // получить случайное число
{
	return (int)dget((double)rmin, (double)rmax);
};

int main()
{
	setlocale(LC_ALL, "rus");
	int d[N][N];
	clock_t  t1, t2;

	t1 = clock();
	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++) {
			d[i][k] = iget(10, 300);
			if (i == k) d[i][k] = 0;
		}

	for (int i=0; i<3; i++)
		d[iget(0, N)][iget(0, N)] = INF;


	int r[N];       // результат
	int s = salesman(
		N,          // [in]  количество городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		r           // [out] массив [n] маршрут 0 x x x x  

	);
	cout << "\n-- Комивояжер -- ";
	cout << "\n-- Сумма городов: " << N;
	cout << "\n-- Матрица расстояний: \n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)

			if (d[i][j] != INF)
				cout << setw(3) << d[i][j] << " ";
			else
				cout << setw(3) << "INF" << " ";
		cout << "\n";
	}

	cout << "\n-- Оптимальный маршрут: ";
	for (int i = 0; i < N; i++)
		cout << r[i] << "-->";
	cout << 0;

	cout << "\n-- Расстояние маршрута: " << s <<"\n";
	t2 = clock();

	
	cout << "\nВремя (сек):   " << (t2 - t1) << "\n";
	system("pause");
	return 0;
}

