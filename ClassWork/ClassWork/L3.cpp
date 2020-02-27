#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

void print(double** matr) {
	int m = _msize(matr) / sizeof(matr);
	int n = _msize(matr[0]) / sizeof(typeid(matr[0]).name());
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matr[i][j] << ' ';
		}
		cout << endl;
	}
}


int main() {

	int* p;

	int x = 10;
	p = &x;


	cout << *p << endl;
	int* p1 = new int;
	delete p1;
	
	int* pArr = new int[10];
	delete[] pArr;

	int size = 5;
	double** pMatr = new double* [size];


	for (int i = 0; i < size; i++) {
		pMatr[i] = new double[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i <= j) {
				pMatr[i][j] = 1;
			}
			else {
				pMatr[i][j] = 0;
			}
			cout << pMatr[i][j] << ' ';
		}
		cout << endl;
	}

	print(pMatr);

	for (int i = 0; i < size; i++) {
		delete[] pMatr[i];
	}

	delete[] pMatr;

	srand((unsigned)time(NULL));
	cout << "random int from -100 to 100: " << rand()<< endl;
}