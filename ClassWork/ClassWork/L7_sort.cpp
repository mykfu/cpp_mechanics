//
// Created by user on 07.05.2020.
//
#include <iostream>
#include <ctime>
using namespace std;

/*
1, 7, 14, 0, 9, 4, 18, 18, 2, 4,
 1, 0, 2, 4, 7, 14, 9, 18, 18
*/

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int left_index = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[left_index]);
            ++left_index;
        }
    }
    swap(arr[left_index], arr[right]);
    return left_index;
}

void quickSort (int *arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

void quickSort(int *arr, int size) {
    quickSort(arr, 0, size - 1);
}


int main() {
//    srand(time(0));
    int size = 10;

    int *arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 20;
        cout << arr[i] << ", ";
    }
    int temp;
//
//    // сортировка пузырьком
//    int *arrBubble = arr;
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arrBubble[j] > arrBubble[j + 1]) {
//                temp = arrBubble[j];
//                arrBubble[j] = arrBubble[j + 1];
//                arrBubble[j + 1] = temp;
//            }
//        }
//    }
//    cout << endl;
//
//    for (int i = 0; i < size; ++i) {
//        cout << arrBubble[i] << ", ";
//    }
//    cout << endl;
//
//    // сортировка вставками
//    int *arrInsert = arr;
//    for (int i = 1; i < size; ++i) {
//        temp = arrInsert[i];
//        for (int prev = i - 1; prev >= 0 && arrInsert[prev] > temp; prev--) {
//            arrInsert[prev + 1] = arrInsert[prev];
//            arrInsert[prev] = temp;
//        }
//    }
//
//    for (int i = 0; i < size; ++i) {
//        cout << arrInsert[i] << ", ";
//    }
    cout << endl;

    // быстрая сортировка

    int *arrQuick = arr;

    quickSort(arrQuick, size);

    for (int i = 0; i < size; ++i) {
        cout << arrQuick[i] << ", ";
    }
    cout << endl;


}