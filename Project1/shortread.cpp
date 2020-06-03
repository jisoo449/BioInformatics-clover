#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"shortread.h"

shortread::shortread(int k, int n, string name1) :shortreadFn(name1), k(k), n(n) {
	ref.generate();
	x = 1;
	y = 2;
}

void shortread::makeShortread() {

	int l = ref.Length();//reference genome의 길이
	int mismatch;
	char c;
	int plag;//plag=0:mismatch x, plag=1:mismathc o

	fout.open(shortreadFn);
	fin.open(ref.Filename());

	srand((unsigned int)time(NULL));

	//n개의 shortread 생성
	for (int i = 0; i < n; i++) {

		plag = 0;
		if (rand() % 100 < x) plag = 1;

		int tmp1 = k + 1, tmp2 = k + 1;
		if (plag = 1) {
			tmp1 = rand() % k;
			while (tmp2 != tmp1) {
				tmp2 = rand() % k;
			}
		}

		fin.seekg(rand() % (l - k + 1), ios::beg);
		for (int j = 0; j < k; j++) {
			//mismatch
			if (j == tmp1 || j == tmp2) {
				mismatch = rand() % 4;
				switch (mismatch) {
				case 0:
					fout << 'A';
					break;
				case 1:
					fout << 'T';
					break;
				case 2:
					fout << 'G';
					break;
				case 3:
					fout << 'C';
					break;
				}
			}
			else {
				fin >> c;
				fout << c;
			}
		}
	}

	fin.close();
	fout.close();
}