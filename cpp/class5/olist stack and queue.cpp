
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

template <class T>
class olist_stack_queue {
private:
	T a[100];
	int n;
	// ***** for stack and queue 
	int top, front, rear;
public:
	olist_stack_queue();
	int Length();
	void Sort();
	void Search(int);
	T read(int i); // retrieve(index i) 的意思
	void store(int i, T j);
	void insert(int i, T v);
	int del(int i);  // 刪除
	void readAll(); // 課本所說 依序印出所有內容
	// ***** for stack and queue
	void push(T);  // for stack
	void pop(T*);   // for stack
	T Top();
	int stackEmpty();
	void QueueAdd(T);  // for queue
	void QueueDel(T*);  // for queue
	T Front();
	int queueEmpty();
};

template <class T>
void olist_stack_queue<T>::insert(int i, T v) {
	/* move rear portion */
	for (int j = n - 1; j >= i; j--) a[j + 1] = a[j];
	/* insert it */
	a[i] = v;
	n++;
}

template <class T>
olist_stack_queue<T>::olist_stack_queue() {
	n = 0;
}

template <class T>
void olist_stack_queue<T>::readAll() {
	int i;
	for (i = 0; i < n; i++)	 cout << a[i] << " ";
	cout << endl;
}

template <class T>
void olist_stack_queue<T>::Sort()
{ //把a[0]至a[n-1]總共n個數以遞增的順序排列
	for (int i = 0; i < n; i++)
	{
		int j = i;
		//找出a[i]到a[n-1]中最小的一個整數
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j]) j = k;
		swap(a[i], a[j]);
	}
}


int main() {
	olist_stack_queue<float> aa;
	aa.insert(0, 34.0);
	aa.insert(1, 21.0);
	aa.insert(0, 5.0);
	aa.insert(0, 9.9);
	aa.readAll();
	aa.Sort();
	aa.readAll();

	olist_stack_queue<char> bb;
	bb.insert(0, 'A');
	bb.insert(1, 'x');
	bb.insert(0, 'm');
	bb.readAll();
	bb.Sort();
	bb.readAll();
	getchar();
}




