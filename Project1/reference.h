#pragma once
#ifndef _REFERENCE_H
#define _REFERENCE_H
using namespace std;
class reference {
	string fn;//레퍼런스 파일의 이름
	ofstream fout;
	const int length = 500000;//dna의 길이
public:
	reference(string name = "reference.txt");
	~reference();
	void generate();
	string Filename();
	int Length();
};
#endif
//+)반복을 줄이는 방법