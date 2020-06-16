#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"reference.h"

reference::reference(int length,string name) :fn(name),length(length) {
	
}

void reference::generate() {
	int dna;
	srand((unsigned)time(NULL));
	int n = length / 4;

	fout.open(fn);
	for (int i = 0; i < n; i++) {
		dna = rand() % 4;
		switch (dna) {
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
		default:
			i--;
			break;
		}
	}

	fout.close();
}

string reference::Filename() {
	return fn;
}

int reference::Length() { return length; }