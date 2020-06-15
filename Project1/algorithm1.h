#pragma once
#ifndef _ALGORITHM1_H
#define _ALGORITHM1_H
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node {
	friend class BSTree<T>;
private:
	T data;
	Node* left;
	Node* right;
	int num; //부모와 얼마나 차이나는지 알려주는 변수

public:
	Node() {
		left = nullptr;
		right = nullptr;
	}
	Node(T t, int num) {
		data = t;
		left = nullptr;
		right = nullptr;
		this->num = num;
	}
	~Node() {	}
};
template<typename T>
class BSTree {
	ofstream fout; //완성된 mydna 출력
	ifstream fin; //short read 호출
public:
	BSTree<T>();
	~BSTree<T>();

	void insertleft(const T &newElement);
	void insertright(const T &newElement);
	bool empty();

	string remake();

	void insertleftSub(Node<T> *&p, const T &newElement);
	void insertrightSub(Node<T> *&p, const T &newElement);
	string remakeSubleft(Node<T> *p);
	string remakeSubright(Node<T> *p);
	bool getleftsuccess{
		return leftsuccess;
	};
	bool getrightsuccess{
		return rightsuccess;
	};
	string myDNAleft;
	string myDNAright;
private:
	Node<T> *root;
	bool leftsuccess;
	bool rightsuccess;

};
#endif // !_ALGORITHM1_H
