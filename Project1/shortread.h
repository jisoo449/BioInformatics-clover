#pragma once
#pragma once
#ifndef _SHORTREAD_H
#define _SHORTREAD_H
using namespace std;
class shortread {
	string shortreadFn;//shortread 파일의 이름
	string refFn;
	ofstream fout;
	ifstream fin;
	int k;//shortread의 길이
	int n;//shortread의 개수
	int length;//dna 길이

	//초기화 필요한 값
	double x;//mismatch가 나올 확률
	int y;//shortread에서 나올 수 있는 mismatch


public:
	shortread(int length, int x, int k, int n, string name1 = "shortread.txt",string name2="reference.txt");//shortread정보 초기화, 레퍼런스 파일 생성
	void makeShortread();//레퍼런스 dna 참고하여 Shortread 파일 생성
};
#endif