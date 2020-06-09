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
	int idx=0;

	//1. 일치하는 부분 찾기
	while (fin1.getline(str1, k)) {
		int j = -1;
		int t = 0;
		int mismatch = 0;//다른 문자의 개수

		computeSP(str1, sp, tablesize);//sp 테이블 생성

		while (fin2.get(str2, k)) {
			for (int i = 0; i < k; i++) {
				//kmp알고리즘 이용하여 특정 부분 중 mismatch이하로 일치하는지 찾아보기
				if (mismatch <= d) {
					if (str1[j + 1] != str2[i])mismatch++;
					j++;
				}
				else {
					mismatch = 0;
					while (j >= 0 && str1[j + 1] != str2[i]) j = sp[j];
				}
				//일치한다면 제대로 비교
				if (j == tablesize - 1) {
					//전체 문자열 가져와서 비교하기(인덱스j부터)
					for (int i = j; i < k; i++) {
						if (str1[i] != str2[i])mismatch++;
						if (mismatch > d)break;
					}
					//다음 문자열 인덱스 저장
					if (mismatch <= d) {
						mismatch = 0;
					}
				}
			}

			//다음 문자열 비교
			memset(sp, NULL, k);
			mismatch = 0;
			idx = idx + i-j;
			fin2.seekg(idx, ios::beg);
		}
	}

	//2. 합치기

	fin1.close();
	fin2.close();

}

void algorithm2::compare() {



}
