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
	int n = length / 4;

	for (int i = 0; i < n; i++) {
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
	for (int i = 0; i < n; i++) {
		dna = rand() % 4;
		switch (dna) {
		case 0:
			fout << "T";
			break;
		case 1:
			fout << "G";
			break;
		case 2:
			fout << "C";
			break;
		case 3:
			fout << "A";
			break;
		default:
			i--;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		dna = rand() % 4;
		switch (dna) {
		case 0:
			fout << "G";
			break;
		case 1:
			fout << "C";
			break;
		case 2:
			fout << "A";
			break;
		case 3:
			fout << "T";
			break;
		default:
			i--;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		dna = rand() % 4;
		switch (dna) {
		case 0:
			fout << "A";
			break;
		case 1:
			fout << "C";
			break;
		case 2:
			fout << "T";
			break;
		case 3:
			fout << "G";
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