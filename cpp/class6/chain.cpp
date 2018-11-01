#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;


template < class T > class Chain;  // �e�V�ŧi				

template < class T >
class ChainNode {
	friend class Chain <T>;
public:
	ChainNode(T e) { data = e; link = 0; }
private:
	T data;
	ChainNode<T>* link;
};

template <class T>
class Chain {
public:
	Chain() { first = 0; } // �غc�l�Nfirst��l�Ʀ�0			
	// �쪺�B�z�B��			
	void add_first(T e);
	void traversal();
	void sum();
	void average();
private:
	ChainNode<T> * first;
};

template <class T>
void Chain<T>::add_first(T e) {
	T st;
	st = e;
	ChainNode<T> *temp = new ChainNode<T>(st);
	temp->link = first;
	first = temp;
}

template <class T>
void Chain<T>::traversal() {
	ChainNode<T> *pt;
	cout << endl;
	for (pt = first; pt != NULL; pt = pt->link) cout << pt->data << "\t";
}

template <class T>
void Chain<T>::sum() {
	ChainNode<T> *pt;
	T total=0;
	for (pt = first; pt != NULL; pt = pt->link){
		total += pt->data;
	}
	cout << "\nsum: " << total << endl;
}

template <class T>
void Chain<T>::average(){
	ChainNode<T> *pt;
	T total=0;
	int count=0;
	for (pt = first; pt != NULL; pt = pt->link){
		total += pt->data;
		count++;
	}
	cout << "\naverage: " << total/count << endl;
}

int main() {
	int aa[7]={3,4,8,99,1,12,13};
	Chain<int> a;
	for(int i=0;i<7;i++)
	a.add_first(aa[i]);
	a.traversal();
	a.sum();
	a.average();

	float bb[4]={3.14,5.69,7.8,4.5};
	Chain<float> b;
	for(int i=0;i<4;i++)
	b.add_first(bb[i]);
	b.traversal();
	b.sum();
	b.average();

	getchar();
}

