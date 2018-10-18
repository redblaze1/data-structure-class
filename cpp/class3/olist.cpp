
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;
template<typename T>
class olist {
private:
	T a[100];
	int n;
public:
	olist();
	int Length();
	void Sort();
	void Search(int);
	T Sum();
	T Average();
	T read(int i); // retrieve(index i) ���N��
	void store(int i, int j);
	void insert(int i,T);
	bool del(int i);  // �R��
	void readAll(); // �ҥ��һ� �̧ǦL�X�Ҧ����e
};
template<typename T>
T olist<T>::read(int i){
	if(i>n){
	cout << "陣列沒有這麼長" << endl;
	return 0;
	}
	return a[i];
}
template<typename T>
bool olist<T>::del(int i){
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
template<typename T>
int olist<T>::Length(){
	return n;
}
template<typename T>
T olist<T>::Sum(){
	T total=0;
	for(int i=0;i<=n;i++){
		total += a[i];
	}
	return total;
}
template<typename T>
T olist<T>::Average(){
	T total=0;
	for(int i=0;i<=n;i++){
		total += a[i];
	}
	return total/n;
}
template<typename T>
void olist<T>::insert(int i, T v) {
	/* move rear portion */
	for (int j = n - 1; j >= i; j--) a[j + 1] = a[j];
	/* insert it */
	a[i] = v;
	n++;
}
template<typename T>
olist<T>::olist() {
	/*
	char *st = "875634921";
	int i;
	for(i=0; i < 9; i++) a[i] = st[i] - '0';
	n = 9;
	*/
	n = 0;
}
template<typename T>
void olist<T>::readAll() {
	int i;
	for (i = 0; i < n; i++)	 cout << a[i] << " ";
	cout << endl;
}

template<typename T>
void olist<T>::Sort()
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
	olist <float>a;
	a.insert(0,34.5);
	a.insert(1,44.7);
	a.insert(2,3.14159);
	a.insert(3,66.7);
	cout << "length: " << a.Length() << endl;
	a.readAll();
	a.Sort();
	cout << "After sort: ";
	a.readAll();

	olist <char>b;
	b.insert(0,'a');
	b.insert(1,'x');
	b.insert(2,'g');
	b.insert(3,'o');
	b.insert(4,'o');
	b.insert(5,'d');
	cout << "length: " << a.Length() << endl;
	b.readAll();
	b.Sort();
	cout << "After sort: ";
	b.readAll();
	// a.insert(0, 3);
	// a.insert(0, 4);
	// a.insert(0, 5);
	// a.insert(1, 9);
	// cout << "read[2] = "<< a.read(2) << endl;
	// cout << "Ave = " << a.Average() << endl;
	// cout << "Sum = " << a.Sum() << endl;
	// cout << "After sort: ";
	// a.Sort();
	// a.readAll();
	// cout << "length: " << a.Length() << endl;
	// a.del(2);
	// a.insert(2, 99);
	// a.insert(0, 88);
	// cout << "目前陣列: ";
	// a.readAll();
	// cout << "Ave = " << a.Average() << endl;
	// cout << "Sum = " << a.Sum() << endl;
	// cout << "After sort: ";
	// a.Sort();
	// a.readAll();
	// cout << "length: " << a.Length() << endl;
	system("Pause");
}




