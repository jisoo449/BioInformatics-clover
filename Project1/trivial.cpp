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

	fin2.open(reference);
	fin2.seekg(0, ios::end);
	size = fin2.tellg();
	refarr = new char[size + 1];
	myarr = new char[size + 1];
	realarr = new char[size + 1];
	fin2.clear();
	fin2.seekg(0, ios::beg);
	char c;
	int i = 0;
	while (fin2.get(c)) {
		refarr[i++] = c;
	}
	fin2.close();
}

void trivial::reconstruct() {
	start = clock();
	fout.open(mydna);
	fin1.open(shortread);

	string str1;
	char c;
	int mismatch=0;
	int i,j,tmpi;
	while(getline(fin1,str1)) {

		for (i = 0; i < size; i++) {
			mismatch = 0;
			for (j = 0; j < k; j++) {
				if (str1[j] != refarr[i+j])mismatch++;
				if (mismatch > d)break;
			}
			if (j == k) {
				for (j = 0; j < k; j++) {
					myarr[i+j] = str1[j];
				}
				break;
			}
		}

	}

	fout.write(myarr, size);
	fin1.close();
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;
}

void trivial::compare() {
	int correct = 0;
	char c;
	int i = 0;
	fin1.open(real);
	while (fin1.get(c)) {
		realarr[i++] = c;
	}
	for (int i = 0; i < size; i++) {
		if (realarr[i] == myarr[i])correct++;
	}
	accuracy = ((double)correct / (double)size) * 100;

	cout << "걸린 시간: " << time << endl;
	cout << "정확도: " << accuracy << "%" << endl;
	cout << "일치한 문자 개수: " << correct << ", 전체 dna 길이: " << size << endl;
	fin1.close();
	fin2.close();
}
