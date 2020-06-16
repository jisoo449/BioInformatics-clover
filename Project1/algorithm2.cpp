#include<string>
#include<fstream>
#include<vector>
#include<queue>
#include<cstdio>
#include<ctime>
#include"algorithm2.h"
#include<iostream>

algorithm2::algorithm2(int k, int n, int d, string real,string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna),real(real) {
	this->n = n;
	this->k = k;
	this->d = d;
}

void algorithm2::computeSP(char* str, int* sp, int size) {
	int K = -1;
	sp[0] = -1;
	for (int i = 0; i < size; i++) {
		while (K >= 0 && str[K + 1] != str[i])K = sp[K];
		if (str[K + 1] == str[i])K++;
		sp[i] = K;
	}
}

void algorithm2::reconstruct() {

	start = clock();

	fout.open(mydna);
	fin1.open(shortread);
	fin2.open(reference);

	char * str1 = new char[k], *str2 = new char[k];//str1:shortread를 저장, str2:reference를 저장
	int tablesize = k / 3;
	int *sp = new int[tablesize];
	int idx=0;

	//1. 일치하는 부분 찾기
	while (fin1.getline(str1, k)) {
		int j = -1;
		int i;
		int t = 0;
		int mismatch = 0;//다른 문자의 개수

		computeSP(str1, sp, tablesize);//sp 테이블 생성

		//문자열 비교
		while (fin2.get(str2, k)) {
			queue<int> sparr;
			queue<int> iarr;
			int tmp;
			int p = 0;//0:while 안거침 , 1: while 거침

			for (i = 0; i < k; i++) {

				//sp 테이블로 일치하지 않는 문자들의 위치 저장
				while (j >= 0 && str1[j + 1] != str2[i]) tmp = sp[j];
				if (p == 1) {
					sparr.push(tmp);
					iarr.push(i);
				}
				
				if (mismatch > d) {
					j = sparr.front();
					i = iarr.front();
					sparr.pop();
					iarr.pop();
					mismatch = 0;
				}

				//한계 이하로 mismatch 발생 시 패턴 비교
				else {
					if (str1[j + 1] != str2[i])mismatch++;
					j++;
					p = 0;
				}

				//패턴이 존재한다면 제대로 비교
				if (j == tablesize - 1) {
					//전체 문자열 가져와서 비교하기(인덱스j부터)
					for (int i = j; i < k; i++) {
						if (str1[i] != str2[i])mismatch++;
						if (mismatch > d)break;
					}
					//다음 문자열 인덱스 저장
					if (mismatch <= d) {
						mismatch = 0;
						idxtable[x].index.push_back(idx + i - j);
					}
				}
				//문자열이 끝났다면 다음으로 보냄
				if (i == k - 1) {
					idx = idx + i - j;
				}
			}

			//다음 문자열 비교
			mismatch = 0;
			fin2.seekg(idx, ios::beg);
		}
		memset(sp, NULL, k);
		x++;
	}

	fin1.close();
	fin2.close();

	//2. 합치기
	int j, vecidx = 0;
	fout.open(mydna);
	fout.seekp(idxtable[0].index[0], ios::beg);
	fout << idxtable[0].sh;
	idxtable[0].index.erase(idxtable[0].index.begin());
	fin1.open(mydna);
	for (int i = 1; i < n; i++) {
		fout.seekp(idxtable[i].index[vecidx], ios::beg);
		fin1.seekg(idxtable[i].index[vecidx], ios::beg);
		fin1.getline(str1, k);
		for (j = 0; j < k; j++) {
			if (str1[j] != ' ') {
				if (str1[j] != idxtable[i].sh[j])break;
			}
		}
		if (j < k) {
			i--;
			vecidx++;
		}
		else {
			fout << idxtable[i].sh;
			vecidx = 0;
		}
	}

	fin1.close();
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;

}

void algorithm2::compare() {
	int correct=0;
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
	
	cout << "걸린 시간: " << time<<endl;
	cout << "정확도: " << accuracy << "%" << endl;

}
