#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>


using namespace std;


class DblListNode {		
friend class DblList;
	private:
		int data;
		DblListNode *right, *left;		
	public:
		DblListNode(int val);
};		

DblListNode::DblListNode(int val) {
	data = val;
	left = right = 0;
}

class DblList {		
public:		
void Insert(DblListNode *p, DblListNode *x);		 // p �Q���J��x���k��
void Delete(DblListNode *x);		 //�R��x
void Print();
void insert_front(int val);
void insert_back(int);
DblList();
private:		
 DblListNode *first;		 // is a head node
};		

DblList::DblList() {
	first = new DblListNode(0);
	first->left = first->right = first;
}

void DblList::Insert(DblListNode *p, DblListNode *x) {
	p->left = x;
	p->right = x->right;
	x->right->left = p;
	x->right = p;
}
void DblList::insert_front(int val) {
	DblListNode *newNode = new DblListNode(val);
	Insert(newNode, first);
}

void DblList::Print() {
	DblListNode *p;
	cout << "content of the doubly linked list" << endl;
	for(p = first->right; p != first; p = p->right) cout << p->data << " ";
}

void DblList::insert_back(int val) {
	DblListNode *p;
	for(p = first->right;; p = p->right){
		if(p->right==first){
			DblListNode *newNode = new DblListNode(val);
			newNode->left = p;
			newNode->right = first;
			p->right->left = newNode;
			p->right = newNode;
			break;
		}
	}
}

int main() {
	DblList a;

	a.insert_front(55);
	a.insert_front(44);
	a.insert_front(33);
	a.Print();
	cout << endl;
	a.insert_back(123);
	a.insert_back(344);
	a.Print();
	getchar();
}
