#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<cstdio>
#include<iostream>
#include<istream>
#include<fstream>
#include "trivial.h"

trivial::trivial(int k, int n, int d, string real, string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna) {
	this->n = n;
	this->k = k;
	this->d = d;
	this->real = real;
}

void trivial::reconstruct() {
	start = clock();

	fout.open(mydna);
	fin1.open(shortread);
	fin2.open(reference);

	char *str1 = new char[k], *str2 = new char[k];
	int idx=0,mismatch=0,i;
	while (fin1.getline(str1, k)) {

		while (fin2.getline(str2, k)) {
			for (i = 0; i < k; i++) {
				if (str1[i] != str2[i])mismatch++;
				if (mismatch > d)break;
			}
			if (i < k) {
				fin2.seekg(++idx, ios::beg);
			}
			else {
				break;
			}
		}
		fout.seekp(idx, ios::beg);
		fout << str1;
		idx=0;
	}

	fin1.close();
	fin2.close();
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;
}

void trivial::compare() {
	int correct = 0;
	char c1, c2;
	fin1.open(real);
	fin2.open(mydna);

	do {
		fin1.get(c1);
		fin2.get(c2);
		if (c1 == c2)correct++;
	} while (!fin1.eof());

	fin1.seekg(0, ios::beg);
	accuracy = (correct / fin1.tellg()) * 100;

	cout << "걸린 시간: " << time << endl;
	cout << "정확도: " << accuracy << "%" << endl;
}
