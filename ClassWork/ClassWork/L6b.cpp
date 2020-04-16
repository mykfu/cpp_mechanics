#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

bool contains(vector<string> &haystack, string needle) { 
	//for (int i = 0; i < haystack.size(); i++) {
	//	if (haystack[i] == needle) {
	//		return true;
	//	}
	//}

	if (find(haystack.begin(), haystack.end(), needle) != haystack.end()) {
		return true;
	}
	return false;
}

int compare(string& str1, string& str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int lim = min(len1, len2);

	int k = 0;

	while (k < lim) {
		char c1 = tolower(str1.at(k));
		char c2 = tolower(str2.at(k));

		if (c1 == 'ё') {
			if (c2 == 'ё') return 0;
			if (c2 == 'е') return 1;
			c1 = 'е';
		}

		if (c2 == 'ё') {
			if (c1 == 'е') return -1;
			c2 = 'е';
		}

		if (c1 != c2) {
			return c1 - c2;
		}
		k++;
	}

	return len1 - len2;
}

int indexOfBinary(vector<string>& haystack, string& needle) {
	int left = 0;
	int right = haystack.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;
		
		//int result = needle.compare(haystack[middle]);
		int result = compare(needle, haystack[middle]);

		if (result == 0) {
			return middle;
		}

		if (result > 0) left = middle + 1;
		else right = middle - 1;

	}
	// а г э
	// д 

	return -1;
}

bool containsBinary(vector<string>& haystack, string& needle) {
	return indexOfBinary(haystack, needle) >= 0 ? true : false;
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
  				&& containsBinary(dictionary, candidate)) {
				result.push_back(candidate);
			}
		}
	}
  	return result;
}

bool game(string in, string out, vector<string> &history, vector<string> &result) {
	if (in == out) {
		cout << "Found!" << endl;
		result.insert(result.begin(), in);
		return true;
	}
	else {
		vector<string> childWords = generateWords(in);
		// hw: add sort
		print(childWords);
		for (int i = 0; i < childWords.size(); i++) {
			if (!contains(history, childWords[i])) {
				history.push_back(childWords[i]);
				//cout << "check " << childWords[i] << endl;
				if (game(childWords[i], out, history, result)) {
					result.insert(result.begin(), in);
					return true;
				}
			}
		}

	}

	return false;
}

void game(string in, string out) {
	vector<string> result;
	vector<string> history;
	if (game(in, out, history, result)) {
		cout << "Цепочка слов для " << in << " => " << out << "; длина цепочки = " << result.size() << ":" <<endl;
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