#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;


template < class T > class Chain;			

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
class Chain{
public:
	Chain() { first = 0; last = 0;}
	void add_first(T);
	void add_last(T);
	void delete_first(T *);
	void delete_last(T *);
	void traversal();
private:
	ChainNode<T> * first;
	ChainNode<T> * last;
	bool isfirst=true;
};

template <class T>
void Chain<T>::add_first(T e) {
	ChainNode<T> *temp = new ChainNode<T>(e);
	temp->link = first;
	if(isfirst){
		last = temp;
		this->isfirst=false;
	}
	first = temp;
}

template <class T>
void Chain<T>::add_last(T e) {
	if(isfirst){
		ChainNode<T> *temp = new ChainNode<T>(e);
		last=temp;
		first = temp;
		isfirst = false;
		return;
	}
	ChainNode<T> *temp = new ChainNode<T>(e);
	last->link = temp;
	last = temp;
}

template <class T>
void Chain<T>::delete_first(T *e) {
	*e = first->data;
	first = first->link;
}

template <class T>
void Chain<T>::delete_last(T *e){
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
void Chain<T>::traversal() {
	ChainNode<T> *pt;
	cout << endl;
	for (pt = first; pt != NULL; pt = pt->link) cout << pt->data << "\t";
}


int main() {
	Chain <char>one;
	one.add_last('m');	one.add_last('i');	one.add_last('l');	one.add_last('k');
	Chain <int>twe;
	twe.add_first(3);	twe.add_first(4);	twe.add_first(5);	twe.add_first(6);

	one.traversal();
	twe.traversal();
	getchar();
}

