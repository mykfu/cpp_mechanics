#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


template<class T>
void print(vector<T> list) {
	cout << "[";
	int n = list.size();
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << (i == n - 1 ? "" : ", ");  // тернарный оператор
	}
	cout << "]\n";
}

vector<string> loadDictionary(string filename) {
	 vector<string> dict;

	ifstream file;

	file.open(filename);
	if (!file) {
		cout << "Файл не открылся!";
		exit(0);
	}

	char* line = new char[50];

	while (!file.eof()) {
		file.getline(line, 50);
		dict.push_back(line);
	}

	file.close();
	return dict;
}
static vector<string>  dictionary = loadDictionary("../../dict_len4.txt");

bool contains(vector<string> haystack, string needle) { // tree?
	for (int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle) {
			return true;
		}
	}
	return false;
}

vector<string> generateWords(string word) {
	string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	vector<string> result;
	for (int i = 0; i < word.size(); i++) {
		string candidate = word;
		for (int j = 0; j < abc.size(); j++) {
			candidate.replace(i, 1, abc.substr(j, 1));
			if (word != candidate
				&& !contains(result, candidate)
  				&& contains(dictionary, candidate)) {
				result.push_back(candidate);
			}
		}
	}
  	return result;
}

bool game(string in, string out, vector<string> history) {
	if (in == out) {
		return true;
	}
	else {
		vector<string> childWords = generateWords(in);
		for (int i = 0; i < childWords.size(); i++) {
			if (!contains(history, childWords[i])) {
				history.push_back(childWords[i]);
				cout << "check " << childWords[i] << endl;
				if (game(childWords[i], out, history)) {
					return true;
				}
			}
		}

	}

	return false;
}

void game(string in, string out) {
	vector<string> result;
	if (game(in, out, result)) {
		print(result);
	}
	else {
		cout << "Не найдено." << endl;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	string in = "стук";
	string out = "слон";
	//print(generateWords(in));

	game(in, out);

}