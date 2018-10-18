
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

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
	bool del(int i);  // �R��
	void readAll(); // �ҥ��һ� �̧ǦL�X�Ҧ����e
};
int olist::read(int i){
	if(i>n){
	cout << "陣列沒有這麼長" << endl;
	return 0;
	}
	return a[i];
}
bool olist::del(int i){
	if (i>n){
	cout << "陣列沒這麼大" << endl;
	return false;
	}
	cout << "成功刪除數字: " << a[i] << endl;
	for(int d=0;d<n-i;d++){
		a[i+d] = a[i+d+1];
	}
	n--;
	return true;
}
int olist::Length(){
	return n;
}
int olist::Sum(){
	int total=0;
	for(int i=0;i<=n;i++){
		total += a[i];
	}
	return total;
}

int olist::Average(){
	int total=0;
	for(int i=0;i<=n;i++){
		total += a[i];
	}
	return total/n;
}

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
	olist a;
	a.insert(0, 3);
	a.insert(0, 4);
	a.insert(0, 5);
	a.insert(1, 9);
	cout << "read[2] = "<< a.read(2) << endl;
	cout << "Ave = " << a.Average() << endl;
	cout << "Sum = " << a.Sum() << endl;
	cout << "After sort: ";
	a.Sort();
	a.readAll();
	cout << "length: " << a.Length() << endl;
	a.del(2);
	a.insert(2, 99);
	a.insert(0, 88);
	cout << "目前陣列: ";
	a.readAll();
	cout << "Ave = " << a.Average() << endl;
	cout << "Sum = " << a.Sum() << endl;
	cout << "After sort: ";
	a.Sort();
	a.readAll();
	cout << "length: " << a.Length() << endl;
	system("Pause");
}




