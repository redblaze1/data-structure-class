#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;


template < class T > class Chain;
template < class T > class CircularList;			

template < class T >
class ChainNode {
	friend class Chain <T>;
	friend class CircularList <T>;
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
	void reverse();
	void Concatenate(Chain<T>);
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
template <class T>
void Chain<T>::Concatenate(Chain<T> b){
	ChainNode<T> *pt;
	int count=0;
	for (pt = first; pt!=NULL; pt = pt->link){
		if(pt->link==NULL){
			pt->link = b.first;
			break;
		}
	}
}

template <class T>
void Chain<T>::reverse(){
	ChainNode<T> * current =first,*previous =0;
	while(current){
		ChainNode<T> *r=previous;
		previous = current;
		current = current->link;
		previous->link=r;
	}
	first=previous;
}

template <class T>
class CircularList{
public:
	CircularList() { first = 0; }		
	void insert_1st(T);
	void insert_last(T);
	void delete_1st(T *);
	void delete_last(T *);
	void traversal();
	void sum();
	void average();
	void reverse();
	void Concatenate(CircularList<T>);
private:
	ChainNode<T> * first;
	ChainNode<T> * last;
	bool isfirst=true;
};

template <class T>
void CircularList<T>::insert_1st(T e) {
	ChainNode<T> *temp = new ChainNode<T>(e);
	temp->link = first;
	if(isfirst){
		last = temp;
		this->isfirst=false;
	}
	first = temp;
}

template <class T>
void CircularList<T>::insert_last(T e) {
	ChainNode<T> *temp = new ChainNode<T>(e);
	last->link = temp;
	last = temp;
}

template <class T>
void CircularList<T>::delete_1st(T *e) {
	*e = first->data;
	first = first->link;
}

template <class T>
void CircularList<T>::delete_last(T *e){
	ChainNode<T> *pt;
	*e = last->data;
	for (pt = first;; pt = pt->link){
		if(pt->link == last){
			pt->link = last->link;
			last = pt;
			break;
		}
	}
}

template <class T>
void CircularList<T>::traversal() {
	ChainNode<T> *pt;
	cout << endl;
	for (pt = first; pt != NULL; pt = pt->link) cout << pt->data << "\t";
}

template <class T>
void CircularList<T>::sum() {
	ChainNode<T> *pt;
	T total=0;
	for (pt = first; pt != NULL; pt = pt->link){
		total += pt->data;
	}
	cout << "\nsum: " << total << endl;
}

template <class T>
void CircularList<T>::average(){
	ChainNode<T> *pt;
	T total=0;
	int count=0;
	for (pt = first; pt != NULL; pt = pt->link){
		total += pt->data;
		count++;
	}
	cout << "\naverage: " << total/count << endl;
}
template <class T>
void CircularList<T>::Concatenate(CircularList b){
	ChainNode<T> *pt;
	int count=0;
	for (pt = first; pt!=NULL; pt = pt->link){
		if(pt->link==NULL){
			pt->link = b.first;
			break;
		}
	}
}

template <class T>
void CircularList<T>::reverse(){
	ChainNode<T> * current =first,*previous =0;
	while(current){
		ChainNode<T> *r=previous;
		previous = current;
		current = current->link;
		previous->link=r;
	}
	first=previous;
}

int main() {
	int val;
	CircularList <int> L;
	L.insert_1st(45);
	L.insert_last(67);
	L.insert_last(12);
	L.insert_1st(30);
	L.insert_1st(20);
	L.traversal();
	cout << endl;
	cout << "delete: ";
	L.delete_1st(&val); cout << val << " ";
	L.delete_1st(&val); cout << val << " ";
	L.delete_last(&val); cout << val << " ";
	L.delete_last(&val); cout << val << " ";
	getchar();
}

