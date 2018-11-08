
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class olist {
private:
	int a[100];
	int n;
public:
	olist();
	int Length();
	void Sort();
	void Search(int);
	int Sum();
	int Average();
	int read(int i); // retrieve(index i) 的意思
	void store(int i, int j);
	void insert(int i, int v);
	int del(int i);  // 刪除
	void readAll(); // 課本所說 依序印出所有內容
};

void olist::insert(int i, int v) {
	/* move rear portion */
	for (int j = n - 1; j >= i; j--) a[j + 1] = a[j];
	/* insert it */
	a[i] = v;
	n++;
}

olist::olist() {
	/*
	char *st = "875634921";
	int i;
	for(i=0; i < 9; i++) a[i] = st[i] - '0';
	n = 9;
	*/
	n = 0;
}

void olist::readAll() {
	int i;
	for (i = 0; i < n; i++)	 cout << a[i] << " ";
	cout << endl;
}


void olist::Sort()
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
	olist aa;
	aa.insert(0, 34);
	aa.insert(1, 21);
	aa.insert(0, 5);
	aa.insert(0, 99);
	aa.readAll();
	aa.Sort();
	aa.readAll();
	getchar();
}




