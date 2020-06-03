#include <iostream>
#include <string> 
#include <cstdio> 
#include <vector> 
#include<ctime>
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
} */

int main(){ 
	string s, p;
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


	return 0; 
}
