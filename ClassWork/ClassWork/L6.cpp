#include "stdafx.h"
#include <iostream>
#include <cstdarg>
using namespace std;

static int counter = 0;

int power(int a, int n) {
	counter++;
	if (n == 0) return 1;
	if (n == 1) return a;
	else {
		if (n % 2 == 0) {
			return power(a * a, n / 2);
		}
		else {
			return a * power(a, n - 1);
		}
	}
}


void print(int* list) {
	cout << "[";
	int n = _msize(list) / sizeof(int);	// так можно узнать размер массива
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << (i == n - 1 ? "" : ", ");  // тернарный оператор
	}
	cout << "]\n";
}

/*вспомогательна¤ функци¤ добавл¤юща¤ элемент в динамический массив*/
int* add(int* source, int m) {
	int size = _msize(source) / sizeof(int);	// так можно узнать размер массива
	int* dest = new int[size + 1];
	for (int i = 0; i < size; i++)
		dest[i] = source[i];
	dest[size] = m;
	delete[] source;
	return dest;
}

/*вспомогательна¤ функци¤ уд¤л¤юща¤ элемент в динамическом массиве под номером pos*/
int* remove(int* source, int pos) {
	int size = _msize(source) / sizeof(int);	// так можно узнать размер массива
	int* dest = new int[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (pos != i) {
			dest[k] = source[i];
			k++;
		}
	}
	delete[] source;
	return dest;
}

void diceRoll(int count, int*& list) {
	if (count == 0) {		// простейший случай. если бросков больше не осталось, выводим комбинациё на экран.
		print(list);
	}
	else {
		for (int i = 1; i <= 6; i++) {     // for all possible choices  
			list = add(list, i);					// добавл¤ем в массив выпавшее число кубика
			diceRoll(count - 1, list);				// рекурси¤ с шагом, убавл¤ем количество кубиков
			int size = _msize(list) / sizeof(int);  // вычисл¤ем размер массива
			list = remove(list, size - 1);			// удал¤ем последний элемент массива
		}
	}

}

void diceRoll(int count) {
	int* list = new int[0]; // создаем пустой динамический массив
	diceRoll(count, list);
}


void diceSum(int count, int*& list, int sum, int currentSum) {
	if (count == 0) {		// простейший случай. если бросков больше не осталось, выводим комбинациё на экран.
		print(list);
	}
	else {
		for (int i = 1; i <= 6; i++) {     // for all possible choices  
			list = add(list, i);					// добавл¤ем в массив выпавшее число кубика
			diceRoll(count - 1, list);				// рекурси¤ с шагом, убавл¤ем количество кубиков
			int size = _msize(list) / sizeof(int);  // вычисл¤ем размер массива
			list = remove(list, size - 1);			// удал¤ем последний элемент массива
		}
	}

}


void diceSum(int count, int sum) {
	int* list = new int[0]; // создаем пустой динамический массив
	diceSum(count, list, sum, 0);
}



int main() {
	cout << power(3, 12) << endl;
	cout << counter << endl;
	diceRoll(2);
}