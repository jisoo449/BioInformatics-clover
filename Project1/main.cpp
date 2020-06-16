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
/*typedef long clock_t;
#define CLOCK_PER_SEC ((clock_t)1000)
vector<int> getPi(string p){ 
	int m = (int)p.size(), j=0;
	vector<int> pi(m, 0);
	for(int i = 1; i< m ; i++){
		while(j > 0 && p[i] != p[j]) j = pi[j-1]; 
		if(p[i] == p[j]) pi[i] = ++j; 
	} return pi;
}

vector<int> kmp(string s, string p){
	vector<int> ans; 
	auto pi = getPi(p); 
	int n = (int)s.size(), m = (int)p.size(), j =0;
	for(int i = 0 ; i < n ; i++){ 
		while(j>0 && s[i] != p[j]) j = pi[j-1]; 
		if(s[i] == p[j]){
			if(j==m-1){
				ans.push_back(i-m+1); 
				j = pi[j]; 
			}
			else{
				j++; 
			}
		}
	}
	return ans; 
} 

int main(){	string s, p;
	clock_t start, end;
	getline(cin, s); 
	getline(cin, p); 

	start = clock();
	cout << s.find(p) << endl;
	end = clock();
	cout << end - start << endl;

	start = clock();
	auto matched = kmp(s,p);
	printf("%d\n", (int)matched.size());
	end = clock();

	for(auto i : matched) printf("%d ", i+1);
	cout <<endl<< end - start << endl << endl;

<<<<<<< HEAD
}
*/

int main(){ 

	shortread shortread(70, 100001000);
	shortread.makeShortread();

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
		bst.insertleft(arr[i]);
		if (bst.getleftsuccess() == true) { //왼쪽 삽입 성공
			cout << "input left" << endl;
			memmove(arr + i, arr + i + 1, arr->size() - i); //완료된 원소는 삭제
			i = 0; //다시 0부터 비교
		}
		else if (bst.getleftsuccess() == false) { //왼쪽 삽입 실패
			bst.insertright(arr[i]); //오른쪽에 비교
			if (bst.getrightsuccess() == true) { //오른쪽 삽입 성공
				cout << "input right" << endl;
				memmove(arr + i, arr + i + 1, arr->size() - i); //완료 원소 삭제
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
	fout.open("myDNA_by_denovo.txt");
	fout.write(myDNA.c_str(), myDNA.size());
	return 0;*/


	//algoritm2
	algorithm2 al2(70, 100001000);// string reference = "reference.txt", string shortread = "shortread.txt", "mydna.txt");
	al2.reconstruct();
	return 0; 
}
