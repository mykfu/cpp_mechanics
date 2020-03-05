// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdarg>
using namespace std;

double f(double x) {
	return sin(x) * sin(x);
}


double g(double x) {
	return sin(x);
}



double integral (double a, double b){
	double sum = 0;

	int n = 100;
	for (int i = 1; i <= n; i++)
	{
		sum += f(a + (i - 0.5) * (b - a) / n);
	}


	return sum * (b - a) / n;
}

double integral (double a, double b, double (*fPointer)(double)){
	double sum = 0;

	int n = 100;
	for (int i = 1; i <= n; i++)
	{
		sum += fPointer(a + (i - 0.5) * (b - a) / n);
	}


	return sum * (b - a) / n;
}


template<class F>
double integral(double a, double b, F f) {
	double sum = 0;

	int n = 100;
	for (int i = 1; i <= n; i++)
	{
		sum += f(a + (i - 0.5) * (b - a) / n);
	}


	return sum * (b - a) / n;
}


//int min(int x, int y) {
//	return 0;
//}
//
//double min(double x, double y) {
//	return 0;
//}

template<typename T>
T min(T x, T y) {
	return (x < y ? x : y);
}

double average(int n, ...) {

	va_list vl;
	double sum = 0;

	va_start(vl, n);
	for (int i = 0; i < n; i++)
	{
		sum+=va_arg(vl, double);
	}
	va_end(vl);

	return sum / n;
}

int main() {

	//cout << average(5, 3, 3.9, 5, 23, 6) << endl;
	cout << min<double>(4.0, 5.2) << endl;

	void (*p)(); // function pointer

	cout << integral(0, 1) << endl;

	// pointer functions:
	cout << integral(0, 1, sin) << endl;
	cout << integral(0, 1, f) << endl;
	cout << integral(0, 1, g) << endl;

	// anonymous function:
	cout << integral(0, 1, [](double x) -> double { return cos(x); }) << endl;
}