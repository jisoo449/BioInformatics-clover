#include <iostream>
#include <fstream>
#include <string> 
#include <cstdio> 
#include <vector> 
#include<ctime>
#include<fstream>
#include"trivial.h"
#include"algorithm1.h"
#include"algorithm2.h"
#include"shortread.h"
#include"reference.h"
using namespace std;

int main() {
	int n=2000000000;//dna 길이
	int l = 70;//shortread 길이
	int m = 200000000;//shortread 개수
	int d=4;//mismatch 개수
	string shname = "shortread.txt", refname = "reference.txt", mydna="mydna.txt",realdna="real.txt";

	reference ref(n, refname);
	ref.generate();
	shortread shortread(n, d,l,m,shname,refname,realdna);
	shortread.makeShortread();

	//trivial
	/*trivial tri(l,m,d,realdna,refname,shname,"trivial.txt");
	tri.reconstruct();
	tri.compare();*/

	/*
	BSTree<string> bst;
	ifstream fin;
	fin.open("shortread.txt");
	cout << "shortread 개수 ?";
	int shortnum;
	cin >> shortnum;
	bool leftsuccess;
	bool rightsuccess;
	clock_t start, end;
	double result;

	start = clock();
	string *arr = new string[shortnum];
	for (int i = 0; i < shortnum; i++) { //쇼트리드를 전부 배열에 입력
		getline(fin, arr[i]);
	}
	int i = 0;
	while (i != shortnum) {
		if (arr[i] == "NULL") { //이미 입력했을 경우 넘기기
			i++;
			continue;
		}
		bst.insert(arr[i]);
		leftsuccess = bst.getleftsuccess();
		rightsuccess = bst.getrightsuccess();
		if (leftsuccess == true) {
			cout << "왼쪽 삽입 성공" << endl;
			i = 0;
			continue;
		}
		else if (leftsuccess == false && rightsuccess == true) {
			cout << "오른쪽 삽입 성공" << endl;
			i = 0;
			continue;
		}
		else if (leftsuccess == false && rightsuccess == false) {
			i++;
			continue;
		}
	}
	string myDNA = bst.remake();
	cout << "복원한 dna길이 : " << myDNA.length() << endl;
	ofstream fout;
	fout.open("myDNA_by_denovo.txt");
	fout.write(myDNA.c_str(), myDNA.size());
	end = clock();
	result = (double)(end - start) / (CLOCKS_PER_SEC);
	cout << "걸린 시간 : " << result << "초" << endl;
	return 0;
	*/

	//algoritm2
	/*algorithm2 al2(l,m,d,realdna,refname,shname,"al2.txt");
	al2.reconstruct();
	al2.compare();*/
	return 0;
}
