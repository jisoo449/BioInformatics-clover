#pragma once
#ifndef _ALGORITHM2_H
#define _ALGORITHM2_H
using namespace std;
struct sh {
	string sh;
	vector<int> index;
	vector<int> mis;
};
class algorithm2 {
	ofstream fout;//fout:mydna
	ifstream fin1, fin2;//fin1s:shortread, fin2: reference 
	int n, k, d; //n:shortread개수, k:shortread길이, d:허용하는 mismatch 개수
	string shortread, mydna, reference,real;
	int x = 2;
	sh* idxtable;

	double accuracy;
	float time;
	clock_t start;

	char *refarr,*myarr,*realarr;
	int size;

public:
	algorithm2( int k, int n, int d, string real="real.txt",string reference = "reference.txt", string shortread = "shortread.txt", string mydna = "mydna.txt");
	void reconstruct();
	void compare();
	void computeSP(string str, int* sp, int size);
	void KMP();
};
#endif
