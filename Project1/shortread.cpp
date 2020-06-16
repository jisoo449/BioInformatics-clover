#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"shortread.h"

shortread::shortread(int length, int x, int k, int n, string name1, string name2) :length(length),x(x), refFn(name2), shortreadFn(name1), k(k), n(n) {}

void shortread::makeShortread() {
	int mismatch;
	char c;
	int plag;//plag=0:mismatch x, plag=1:mismathc o

	fout.open("real.txt");
	fin.open(refFn);

	srand((unsigned int)time(NULL));
	do {
		fin.get(c);
		if (rand() % 100 < x) {
			switch (mismatch = rand() % 4) {
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
	} while (!fin.eof());
	fin.close(); fout.close();
	
	char *str = new char[k];
	fin.open("real.txt"); fout.open(shortreadFn);
	//n개의 shortread 생성
	for (int i = 0; i < n; i++) {

		fin.seekg(rand() % (length - k + 1), ios::beg);
		fin.getline(str, k);
		fout << str << endl;
	}
	fin.close();fout.close();
}