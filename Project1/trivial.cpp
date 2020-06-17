#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<cstdio>
#include<iostream>
#include<istream>
#include<fstream>
#include "trivial.h"

trivial::trivial(int k, int n, int d, string real, string reference, string shortread, string mydna) :reference(reference), shortread(shortread), mydna(mydna) {
   this->n = n;
   this->k = k;
   this->d = d;
   this->real = real;
}

void trivial::reconstruct() {
   start = clock();

   fout.open(mydna);
   fin1.open(shortread);
   fin2.open(reference);

   char *str1 = new char[k], *str2 = new char[k];
   char c;
   int idx=0,mismatch=0,i=0;
   while (fin1.getline(str1, k)) {

      do {
         fin2.get(c);
         if (str1[i] == c) i++;
         else mismatch++;
         if (mismatch > d) {
            mismatch = 0;
            i = 0;
            fin1.seekg(++idx, ios::beg);
         }
      }while (!fin2.eof()||i<k);

      fout.seekp(idx, ios::beg);
      fout << str1;
      i = 0;
      idx = 0;
      mismatch = 0;
   }

   fin1.close();
   fin2.close();
   fout.close();

   time = (float)(clock() - start) / CLOCKS_PER_SEC;
}

void trivial::compare() {
   int correct = 0,size=0;
   char c1, c2;
   fin1.open(real);
   fin2.open(mydna);

   do {
      fin1.get(c1);
      fin2.get(c2);
      if (c1 == c2)correct++;
      size++;
   } while (!fin1.eof());

   fin1.seekg(0, ios::beg);
   accuracy = (correct / size) * 100;

   //cout << "걸린 시간: " << time << endl;
   cout << "정확도: " << accuracy << "%" << endl;
   cout << "일치한 문자 개수: " << correct << endl;cout << ", 전체 dna 길이: " << fin1.tellg() << endl;
   fin1.close();
   fin2.close();
}
