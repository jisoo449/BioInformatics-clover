#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<cstdio>
#include<iostream>
#include<istream>
#include<fstream>
#include<string>
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

	string str1;
	char *str2 = new char[k + 1];
	char c;
	int idx = 0, mismatch = 0, i = 0;
	while (getline(fin1, str1)) {
		do {
			fin2.get(c);
			if (str1[i] == c) i++;
			else {
				mismatch++;
				i++;
			}
			if (mismatch > d) {
				mismatch = 0;
				i = 0;
				fin2.clear();
				fin2.seekg(++idx, ios::beg);
			}
			if (i == k) break;
		} while (!fin2.eof());
		if (i == k) {
			fout.clear();
			fout.seekp(idx, ios::beg);
			fout << str1;
		}
		i = 0;
		idx = 0;
		mismatch = 0;
	}

	fin1.close();
	fin2.close();
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;
}

void trivial::compare() {
	int correct = 0, size = 0;
	char c1, c2;
	fin1.open(real);
	fin2.open(mydna);
	fin1.seekg(0, ios::end);
	size = fin1.tellg();
	fin1.clear();
	fin1.seekg(0, ios::beg);
	fin2.seekg(0, ios::beg);
	do {
		fin1.get(c1);
		fin2.get(c2);
		if (c1 == c2)correct++;

	} while (!fin1.eof() || !fin2.eof());
	accuracy = ((double)correct / (double)size) * 100;

	cout << "걸린 시간: " << time << endl;
	cout << "정확도: " << accuracy << "%" << endl;
	cout << "일치한 문자 개수: " << correct << ", 전체 dna 길이: " << size << endl;
	fin1.close();
	fin2.close();
}
