#pragma once
#ifndef _ALGORITHM2_H
#define _ALGORITHM2_H
using namespace std;
class algorithm2 {
	string ref, sh;
	istream fin1, fin2;//fin1: shortread, fin2: reference
	ofstream fout;//restructed
public:
	algorithm2() {
		
	}
	algorithm2(string ref, string sh) : ref(ref), sh(sh) {
		fin1.open(sh);
		fin2.open(ref);
	}
	void readfile();
};
#endif