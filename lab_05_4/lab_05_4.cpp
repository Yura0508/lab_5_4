﻿// lab_05_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;
double S0(const int k, const int N)
{
	double s = 0;
	for (int i = k; i <= N; i++)
		s += 1.0 / pow(2 * k + 1, 2);
	return s;
}
double S1(const int k, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return 1.0 / pow(2 * k + 1, 2) + S1(k, N, i + 1);
}
double S2(const int k, const int N, const int i)
{
	if (i < k)
		return 0;
	else
		return 1.0 / pow(2 * k + 1, 2) + S2(k, N, i - 1);
}
double S3(const int k, const int N, const int i, double t)
{
	t = t + (1.0 / pow(2 * k + 1, 2));
	if (i >= N)
		return t;
	else
		return S3(k, N, i + 1, t);
}
double S4(const int k, const int N, const int i, double t)
{
	t = t + (1.0 / pow(2 * k + 1, 2));
	if (i <= k)
		return t;
	else
		return S4(k, N, i - 1, t);
}
int main()
{
	int k, N;
	k = 1;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(k, N) << endl;
	cout << "(rec up ++) S1 = " << S1(k, N, k) << endl;
	cout << "(rec up --) S2 = " << S2(k, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(k, N, k, 0) << endl;
	cout << "(rec down --) S4 = " << S4(k, N, N, 0) << endl;
	return 0;
}