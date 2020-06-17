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

void algorithm2::computeSP(string str, int* sp, int size) {
	int K = -1;
	sp[0] = -1;
	for (int i = 1; i <= size-1; i++) {
		while (K > 0 && str[K + 1] != str[i]) {
			K = sp[K - 1];
		}
		if (str[K+1] == str[i]) {
			K++;
			sp[i] = K;
		}
		else {
			sp[i] = 0;
		}
	}
}

void algorithm2::reconstruct() {

	start = clock();

	fout.open(mydna);
	fin1.open(shortread);
	fin2.open(reference);
	
	string str1; char *str2 = new char[k];//str1:shortread를 저장, str2:reference를 저장
	int tablesize = k / 3+1;
	int *sp = new int[tablesize];
	int idx=0;

	// reference크기
	fin1.seekg(0, ios::end);
	int size = fin1.tellg();
	fin1.clear();
	fin1.seekg(0, ios::beg);

	//1. 일치하는 부분 찾기
	while (getline(fin1, str1)) {
		int j = -1;
		int i;
		int t = 0;
		int mismatch = 0;//다른 문자의 개수
		idx = 0;
		computeSP(str1, sp, tablesize);//sp 테이블 생성

		//문자열 비교
		while(idx<size-k) {
			queue<int> sparr;
			queue<int> iarr;
			int tmp;
			int p = 0;//0:while 안거침 , 1: while 거침

			fin2.get(str2, k);
			for (i = 0; i < k; i++) {

				//sp 테이블로 일치하지 않는 문자들의 위치 저장
				tmp = j;
				while (tmp > 0 && str1[tmp + 1] != str2[i]) {
					tmp = sp[tmp];
					p = 1;
				}
				if (p == 1) {
					sparr.push(tmp);
					iarr.push(i);
					p = 0;
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
			fin2.clear();
			fin2.seekg(idx, ios::beg);
		}
		memset(sp, NULL, k);
		x++;
	}

	fin1.close();
	fin2.close();

	//2. 합치기
	int j, vecidx = 0;
	char *s = new char[k];
	fout.open(mydna);
	fout.seekp(idxtable[0].index[0], ios::beg);
	fout << idxtable[0].sh;
	idxtable[0].index.erase(idxtable[0].index.begin());
	for (int i = 1; i < n; i++) {
		fout.seekp(idxtable[i].index[vecidx], ios::beg);
		fout << idxtable[i].sh;
		/*fin1.clear();
		fin1.seekg(idxtable[i].index[vecidx], ios::beg);
		fin1.getline(s, k);
		for (j = 0; j < k; j++) {
			if (s[j] != ' ') {
				if (s[j] != idxtable[i].sh[j])break;
			}
		}
		if (j < k) {
			i--;
			vecidx++;
		}
		else {
			fout << idxtable[i].sh;
			vecidx = 0;
		}*/
	}
	fout.close();

	time = (float)(clock() - start) / CLOCKS_PER_SEC;

}

void algorithm2::compare() {
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
