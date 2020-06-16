#pragma once
#ifndef _TRIVIAL_H
#define _TRIVIAL_H
using namespace std;

class trivial {
	ofstream fout;
	ifstream fin1, fin2;
	int n, k, d; //n:개수, k:길이, d:shortread 개수
	string shortread, mydna, reference, real;
	int x = 2;
	float time;
	double accuracy;
	clock_t start;

public:
	trivial(int k, int n, int d,string real="real.txt", string reference = "reference.txt", string shortread = "shortread.txt", string mydna = "mydna.txt");
	void reconstruct();
	void compare();
};
#endif