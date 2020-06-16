#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"shortread.h"

using namespace std;

shortread::shortread(int length, int x, int k, int n, string name1, string name2) :length(length), x(x), shortreadFn(name1), k(k), n(n), refFn(name2) {
}

void shortread::makeShortread() {
	int mismatch;
	char c;
	fin.open(refFn);
	fout.open("real.txt");
	char ch;
	int temp;
	do {
		fin.get(ch);
		if (temp=rand() % 100 < 4) {
			switch (temp) {
			case 0:
				ch = 'A';
				break;
			case 1:
				ch = 'T';
				break;
			case 2:
				ch = 'G';
				break;
			case 3:
				ch= 'C';
				break;
			}
		}
		cout << ch;
		fout << ch;
	} while (!fin.eof());
	fin.close();
	fout.close();
	cout << endl << endl;

	fin.open("real.txt");
	fout.open(shortreadFn);
	srand((unsigned int)time(NULL));

	char* str=new char[k+1];
	//n개의 shortread 생성
	for (int i = 0; i < n; i++) {
		fin.seekg(rand() % (length - k + 1), ios::beg);
		fin.getline(str,k);
		cout << str << endl;
		fout << str << endl;
	}
		
	fin.close();
	fout.close();
}