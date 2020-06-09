#pragma once
#ifndef _ALGORITHM2_H
#define _ALGORITHM2_H
using namespace std;

class algorithm2 {
	ofstream fout;//fout:mydna
	ifstream fin1, fin2;//fin1:shortread, fin2: reference 
	int n, k, d; //n:shortread개수, k:shortread길이, d:허용하는 mismatch 개수
	string shortread, mydna, reference;
	int x = 2;

public:
	algorithm2(int k, int n, string reference = "reference.txt", string shortread = "shortread.txt", string mydna = "mydna.txt");
	void reconstruct();
	void compare();
	void computeSP(char* str, int* sp, int size);
	void KMP();
};
#endif