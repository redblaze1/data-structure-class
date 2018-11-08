
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
	int read(int i); // retrieve(index i) ���N��
	void store(int i, int j);
	void insert(int i, int v);
	int del(int i);  // �R��
	void readAll(); // �ҥ��һ� �̧ǦL�X�Ҧ����e
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
{ //��a[0]��a[n-1]�`�@n�ӼƥH���W�����ǱƦC
	for (int i = 0; i < n; i++)
	{
		int j = i;
		//��Xa[i]��a[n-1]���̤p���@�Ӿ��
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




