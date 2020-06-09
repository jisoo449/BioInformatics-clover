#include<string>
#include<fstream>
#include<vector>
#include"algorithm2.h"


algorithm2::algorithm2(int k, int n, string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna) {
	this->n = n;
	this->k = k;

	idx = new int[n];
	loc = new char*[n];
	for (int i = 0; i < n; i++)loc[i] = new char[k + 1];
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

	fout.open(mydna);
	fin1.open(shortread);
	fin2.open(reference);

	char * str1 = new char[k], *str2 = new char[k];//str1:shortread를 저장, str2:reference를 저장
	int tablesize = k / 3;
	int *sp = new int[tablesize];

	while (fin1.getline(str1, k)) {
		int j = -1;
		int t = 0;
		int mismatch = 0;//다른 문자의 개수

		computeSP(str1, sp, tablesize);//sp 테이블 생성

		while (fin2.get(str2, k)) {
			for (int i = 0; i < k - 1; i++) {
				//kmp알고리즘 이용하여 특정 부분 중 mismatch이하로 일치하는지 찾아보기
				while (j >= 0 && str1[j + 1] != str2[i]) j = sp[j];
				if (str1[j + 1] != str2[i])mismatch++;
				else if (str1[j + 1] == str2[i] && mismatch <= d) {
					j++;
				}
				else if (mismatch > d)break;

				//일치한다면 제대로 비교
				if (j == tablesize - 1) {
					//전체 문자열 가져와서 비교하기(인덱스j부터)
					//
				}
			}
		}


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

		memset(sp, NULL, k);
	}

	for (int i = 0; i < n; i++) {

	}

	fout.close();

}

void algorithm2::compare() {



}
