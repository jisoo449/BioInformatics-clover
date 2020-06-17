#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"shortread.h"

shortread::shortread(int length, int x, int k, int n, string name1, string name2,string real) :real(real),length(length),x(x), refFn(name2), shortreadFn(name1), k(k), n(n) {}

void shortread::makeShortread() {
	int mismatch;
	char c;
	int plag;//plag=0:mismatch x, plag=1:mismathc o

	fout.open(real);
	fin.open(refFn);

	srand((unsigned int)time(NULL));
	do {
		fin.get(c);
		if (rand() % 100 < x) {
			switch (mismatch = rand() % 4) {
			case 0:
				c = 'A';
				break;
			case 1:
				c = 'T';
				break;
			case 2:
				c = 'G';
				break;
			case 3:

				c= 'C';
				break;
			}
		}
		fout << c;
	} while (!fin.eof());
	fin.close(); fout.close();
	
	char str;
	int j = 0;
	fin.open(real); fout.open(shortreadFn);
	//n개의 shortread 생성
	for (int i = 0; i < n; i++) {
		fin.seekg(rand() % (length - k + 1), ios::beg);
		do {
			fin.get(c);
			fout << c;
			j++;
			if (j > k)break;
		} while (!fin.eof());
		fout << endl;
		j = 0;
	}
	fin.close();fout.close();
}
