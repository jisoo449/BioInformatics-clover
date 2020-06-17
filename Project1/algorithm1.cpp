#include"algorithm2.h"
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
void BSTree<T>::insert(const string &newElement, int oknum) {
	return insertSub(root, newElement, oknum);
}

template<typename T>
void BSTree<T>::insertSub(Node<T> *&p, const string &newElement, int oknum) {
	if (p == nullptr) { //첫 입력일때
		p = new Node<string>(newElement, 0);
		leftsuccess = true;
	}

	if (p->left != nullptr) //왼쪽 자식이 비어있지 않으면 계속 넘어가기;
		insertSub(p->left, newElement, oknum);

	else if (p->left == nullptr) { //왼쪽 자식 비어있을때
		string temp = p->data;
		int newLen = newElement.length(); //쇼트리드 길이
		bool insertEnd = false;
		for (int i = 0; i < newLen-oknum-1; i++) { //newElement 비교 시작 인덱스
			for (int j = 0; j < newLen; j++) {
				if (i + j == newElement.length()) {
					p->left = new Node<string>(newElement, i); //0부터 i-1번째까지 앞에 추가됨
					insertEnd = true;
					break;
				}
				if (temp[j] != newElement[i + j])
					break;
			}
			if (insertEnd) {//삽입 완료
				leftsuccess = true;
				break;
			}
			else if (!insertEnd) {
				leftsuccess = false;
				insertrightSub(root, newElement, oknum); //오른쪽 비교
			}
		}
	}
}

template<typename T>
void BSTree<T>::insertrightSub(Node<T> *&p, const string &newElement, int oknum) {
	if (p->right != nullptr) { //오른쪽이 비어있을 때까지 넘기기
		insertrightSub(p->right, newElement, oknum);
	}
	else if (p->right == nullptr) {
		string temp = p->data;
		int tempLen = temp.length();
		bool insertEnd = false;
		for (int i = 0; i < tempLen-oknum-1; i++) { //p비교 시작 인덱스
			for (int j = 0; j < newElement.length(); j++) { //새 원소 비교 시작 인덱스
				if (i + j == newElement.length()) {
					p->right = new Node<string>(newElement, j); //j부터 newElement 길이까지 뒤에 추가됨;
					insertEnd = true;
					break;
				}
				if (temp[i + j] != newElement[j])
					break;
				else if (temp[i + j] == newElement[j])
					continue;
			}
			if (insertEnd) { //삽입 완료
				rightsuccess = true;
				break;
			}
			else if (!insertEnd) { //오른쪽 삽입 실패
				rightsuccess = false;
			}
		}
	}
}

template<typename T>
string BSTree<T>::remake() {
	string left = remakeSubleft(root);
	string right = remakeSubright(root->right);
	return left + right;
}

template<typename T>
string BSTree<T>::remakeSubleft(Node<T>*p) {
	if (p == nullptr) {
		cout << "nothing on leftside" << endl;
		return myDNAleft;
	}
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
	if (p == nullptr) {
		cout << "nothing on right side" << endl;
		return myDNAright;
	}
	if (p->right != nullptr) {
		string tempshort = p->data.substr(p->num);
		myDNAright = myDNAright + tempshort;
		remakeSubright(p->right);
	}
	else if (p->right == nullptr) {
		string tempshort = p->data.substr(p->num);
		myDNAright = myDNAright + tempshort;
	}
	return myDNAright;
}
