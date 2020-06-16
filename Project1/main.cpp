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

	/*BSTree<string> bst;
	ifstream fin;
	fin.open("shortread.txt");
	cout << "shortread 개수 ?";
	int shortnum;
	cin >> shortnum;

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
		bst.insertleft(arr[i]);
		if (bst.getleftsuccess() == true) { //왼쪽 삽입 성공
			cout << "input left" << endl;
			arr[i] = "NULL"; //완료된 원소는 삭제
			i = 0; //다시 0부터 비교
		}
		else if (bst.getleftsuccess() == false) { //왼쪽 삽입 실패
			bst.insertright(arr[i]); //오른쪽에 비교
			if (bst.getrightsuccess() == true) { //오른쪽 삽입 성공
				cout << "input right" << endl;
				arr[i] = "NULL"; //완료 원소 삭제
				i = 0; //다시 0부터 비교
			}
			else if (bst.getrightsuccess() == false) { //오른쪽도 삽입 실패
				i++; //i증가 후 비교
				continue;
			}
		}
	}
	string myDNA = bst.remake();
	ofstream fout;
	cout <<"\nresult"<< myDNA << endl;
	fout.open("myDNA_by_denovo.txt");
	fout.write(myDNA.c_str(), myDNA.size());
	*/

	//algoritm2
	/*algorithm2 al2(l,m,d,realdna,refname,shname,"al2.txt");
	al2.reconstruct();
	al2.compare();*/
	return 0;
}
