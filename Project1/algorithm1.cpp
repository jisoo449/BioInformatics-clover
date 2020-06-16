#include"algorithm1.h"
template<typename T>
BSTree<T>::BSTree() {
	root = nullptr;
}

template<typename T>
BSTree<T>::~BSTree() {
	delete root;
}

template<typename T>
bool BSTree<T>::empty() {
	if (root == nullptr)
		return true; //root가 비어있으면 true반환
	return false;
}

template<typename T>
void BSTree<T>::insertleft(const string &newElement) {
	if (empty()) {
		root = new Node<string>(newElement, 0);
	}
	else
		return insertleftSub(root, newElement);
}

template<typename T>
void BSTree<T>::insertright(const string &newElement) {
	return insertrightSub(root, newElement);
}
template<typename T>
void BSTree<T>::insertleftSub(Node<T> *&p, const string &newElement) {
	if (p->left != NULL) { //왼쪽 자식이 비어있지 않으면 계속 넘어가기
		p = p->left;
		insertleftSub(p, newElement);
	}
	else if (p->left == NULL) {
		string temp = p->data;
		int tempLen = temp.length(); //쇼트리드 길이
		int endP = tempLen / 3;
		bool insertEnd = false;
		for (int i = 0; i < endP; i++) { //newElement 비교 시작 인덱스
			for (int j = 0; j < tempLen; j++) {
				if (i + j == newElement.length()) {
					p->left = new Node<string>(newElement, i); //0부터 i-1번째까지 앞에 추가됨
					leftsuccess = true;
					insertEnd = true;
					break;
				}
				if (temp[j] != newElement[i + j])
					break;
				else if (temp[j] == newElement[i + j])
					continue;
			}
			if (insertEnd == true) //삽입완료
				break;
		}
		if (p->left = nullptr)
			leftsuccess = false; //왼쪽 삽입 실패시 오른쪽으로
	}
}

template<typename T>
void BSTree<T>::insertrightSub(Node<T> *&p, const string &newElement) {
	if (p->right != NULL) {
		p = p->right;
		insertrightSub(p, newElement);
	}
	else if (p->right == NULL) {
		string temp = p->data;
		int tempLen = temp.length();
		int startP = tempLen / 3;
		bool insertEnd = false;
		for (int i = 0; i < startP; i++) { //p비교 시작 인덱스
			for (int j = 0; j < newElement.length(); j++) { //새 원소 비교 시작 인덱스
				if (i + j == newElement.length()) {
					p->right = new Node<string>(newElement, j); //j부터 newElement 길이까지 뒤에 추가됨
					rightsuccess = true;
					insertEnd = true;
					break;
				}
				if (temp[i + j] != newElement[j])
					break;
				else if (temp[i + j] == newElement[j])
					continue;
			}
			if (insertEnd == true) //삽입 완료
				break;
		}
		if (p->right = nullptr)
			rightsuccess = false;
	}
}

template<typename T>
string BSTree<T>::remake() {
	string left= remakeSubleft(root);
	string right = remakeSubright(root->right);
	return left + right;
}

template<typename T>
string BSTree<T>::remakeSubleft(Node<T>*p) {
	if (p->left != nullptr) {
		remakeSubleft(p->left);
		int tempnum = p->num;
		string tempshort = p->data.substr(p->num);
		myDNAleft = myDNAleft + tempshort;
	}
	if (p->left == nullptr) //가장 왼쪽 끝의 노드값 더하기
		myDNAleft = p->data;

	return myDNAleft;
}
template<typename T>
string BSTree<T>::remakeSubright(Node<T>*p) {
	if (p->right != nullptr) {
		string tempshort = p->data.substr(p->num);
		myDNAright = myDNAright + tempshort;
		remakeSubright(p -> right);
	}
	else if (p->right == nullptr) {
		string tempshort = p->data.substr(p->num);
		myDNAright = myDNAright + tempshort;
	}

	return myDNAright;
}