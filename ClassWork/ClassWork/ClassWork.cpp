// ClassWork_17.cpp: определяет точку входа для консольного приложения.
//

// #include "stdafx.h"
#include <iostream>
using namespace std;

void print(int arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1) cout << "; ";
	}
	cout << "]" << endl;
}

void print(char arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (arr[i] == '\0') cout << "\\0";
		if (i != size - 1) cout << "; ";
	}
	cout << "]" << endl;
}

void print(int arr[][10]) {


}

int main()
{
	cout << "Hello World!\n\0";

	// type name[size];
	const int size = 10;
	// задаем целочисленный массив длиной size, первые 4 элемента задаются конкретно, остальные будут 0.
	int nums[size] = {1, 2, 3, 4};
	print(nums, sizeof(nums) / sizeof(int));
	cout << nums[11] << endl;

	char s[7] = "Hello!";
	print(s, size);

	int nums2[size];


	for (int i = 0; i < size; i++) {
		nums2[i] = nums[i];
	}
	print(nums2, size);

	// type name[rows][cols]

	int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int matrix2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};




}
