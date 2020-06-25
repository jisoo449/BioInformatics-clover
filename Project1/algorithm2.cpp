#include<string>
#include<fstream>
#include<vector>
#include<queue>
#include<cstdio>
#include<ctime>
#include"algorithm2.h"
#include<iostream>

algorithm2::algorithm2(int k, int n, int d, string real, string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna), real(real) {
	this->n = n;
	this->k = k;
	this->d = d;
	idxtable = new sh[n+1];
	fin2.open(reference);

	// reference 배열에 옮기기
	fin2.seekg(0, ios::end);
	size = fin2.tellg();
	refarr = new char[size+1];
	myarr = new char[size+1];
	realarr = new char[size+1];
	fin2.clear();
	fin2.seekg(0, ios::beg);
	char c;
	int i = 0;
	while (fin2.get(c)) {
		refarr[i++] = c;
	}
	fin2.close();
}

void algorithm2::computeSP(string str, int* sp, int size) {
	
	int K = 0;
	sp[0] = 0;
	for (int i = 1; i < size; i++) {
		while (K > 0 && str[K] != str[i]) K = sp[K-1];
		if (str[K] == str[i]) K++;
		sp[i] = K;
	}
}

//복구
void algorithm2::reconstruct() {
	start = clock();

	fin1.open(shortread);

	string str1;// char *str2 = new char[k+1];//str1:shortread를 저장, str2:reference를 저장
	int tablesize = k / 3;
	int *sp = new int[tablesize];

	fin1.clear();
	fin1.seekg(0, ios::beg);

	int l=-1;

	int i;
	int j;
	int ii;
	int jj;
	int mismatch;
	int tmpj;
	int tmpi;
	int tmpmis;

	//1. 일치하는 부분 찾기
	while (getline(fin1, str1)) {
		mismatch = 0;//다른 문자의 개수
		computeSP(str1, sp, tablesize);//sp 테이블 생성
		j = 0;
		l++;
		idxtable[l].sh = str1;
		//문자열 비교
		for (i = 0; i < size; i++) {

			if(mismatch>d){
				i = ii;
				j = jj;
				mismatch = 0;
				while (j > 0 && str1[j] != refarr[i]) {
					j = sp[j-1];
				}
			}

			else {
				if (str1[j] != refarr[i]) {
					if (mismatch == 0) {
						ii = i;
						jj = j;
					}
					mismatch++;
				}
				j++;
			}

			if (j == tablesize && mismatch<=d) {
				tmpi = i+1;
				tmpj = j;
				tmpmis = mismatch;
				while (tmpmis <= d && tmpj<k && tmpi<size) {
					if (str1[tmpj++] != refarr[tmpi++]) tmpmis++;
				}
				if (tmpmis <= d && tmpj == k) {
					idxtable[l].index.push_back(tmpi - tmpj);
					idxtable[l].mis.push_back(tmpmis);
				}
					
				if (mismatch == 0)j = sp[j - 1];
				else mismatch = d + 1;

			}
			if (k-j+i > size) {  break;  }
		}

		memset(sp, 0, tablesize);
	}
	fin1.close();

	//2. 합치기
	int vecidx = 0;
	int min=0,minidx;
	for (int i = 0; i < n; i++) {
		vecidx = idxtable[i].index.size();
		switch (vecidx) {
		case 0:
			break;
		case 1:
			for (j = 0; j < k; j++) {
				myarr[idxtable[i].index[0] + j] = idxtable[i].sh[j];
			}
			break;
		default:
			min = d;
			for (j = 0; j < vecidx; j++) {
				if (idxtable[i].mis[j] < min) {
					min = idxtable[i].mis[j];
					minidx = j;
				} 
			}
			for (j = 0; j < k; j++) {
				myarr[idxtable[i].index[minidx] + j] = idxtable[i].sh[j];
			}
			break;
		}
	}

	fout.open(mydna);
	fout.write(myarr, size);
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;

}

void algorithm2::compare() {
	int correct = 0;
	fin1.open(real);

	int i = 0;
	char c;
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
	//fin2.close();

}
