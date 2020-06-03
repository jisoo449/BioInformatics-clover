#pragma once
#ifndef _TRIVIAL_H
#define _TRIVIAL_H
using namespace std;

class trivial {
	ofstream fout;
	ifstream fin1, fin2;
	int n, k; //n:개수, k:길이
	string shortread, mydna, reference;
	int x = 2;

	int *idx;
	char **loc;

public:
	trivial(int k, int n, string reference = "reference.txt", string shortread = "shortread.txt", string mydna = "mydna.txt");
	void reconstruct();
	void compare();
};
#endif