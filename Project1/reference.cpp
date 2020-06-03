#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"reference.h"

reference::reference(string name) :fn(name) {
	fout.open(fn);
}

reference::~reference() {
	fout.close();
}

void reference::generate() {
	int dna;
	srand((unsigned)time(NULL));

	for (int i = 0; i < length; i++) {
		dna = rand() % 4;

		switch (dna) {
		case 0:
			fout << "A";
			break;
		case 1:
			fout << "T";
			break;
		case 2:
			fout << "G";
			break;
		case 3:
			fout << "C";
			break;
		default:
			i--;
			break;
		}
	}
}

string reference::Filename() {
	return fn;
}

int reference::Length() { return length; }