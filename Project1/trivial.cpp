#include<iostream>
#include<istream>
#include<fstream>
#include "trivial.h"

trivial::trivial(int k, int n, string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna) {
	this->n = n;
	this->k = k;

	idx = new int[n];
	loc = new char*[n];
	for (int i = 0; i < n; i++)loc[i] = new char[k + 1];
}

void trivial::reconstruct() {

	fout.open(mydna);
	fin1.open(shortread);
	fin2.open(reference);

	char * str1 = new char[k], *str2 = new char[k];//str1:shortread를 저장, str2:reference를 저장

	while (fin1.getline(str1, k)) {
		int i = 0;
		int t = 0;
		int n = 0;//다른 문자의 개수
		while (fin2.getline(str2, k)) {

			for (int j = 0; j < k; j++) {
				if (str1[j] != str2[j]) n++;
				if (n > 2) break;
			}
			if (n == 2 || n == 0) {
				idx[t] = i;
				strcpy(loc[t++], str1);
			}

			fin2.seekg(++i, ios::beg);
		}
	}

	for (int i = 0; i < n; i++) {

	}

	fout.close();

}

void trivial::compare() {



}
