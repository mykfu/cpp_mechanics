#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	ifstream file;

	file.open("../../dict_len4.txt");
	if (!file) {
		cout << "Файл не открылся!";
		return -1;
	}

	string* dict;
	char* line = new char[50];

	while (!file.eof()) {
		file.getline(line, 50);

		cout << line << endl;

	}

	file.close();

}