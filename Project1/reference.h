#pragma once
#ifndef _REFERENCE_H
#define _REFERENCE_H
using namespace std;
class reference {
	string fn;//레퍼런스 파일의 이름
	ofstream fout;
	const int length;//dna의 길이
public:
	reference(int length, string name = "reference.txt");
	void generate();
	string Filename();
	int Length();
};
#endif
//+)반복을 줄이는 방법