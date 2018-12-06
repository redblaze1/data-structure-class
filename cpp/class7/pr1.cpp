
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
	void reverse();
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
void olist<T>::reverse() {
	bool is_even=false;
	if(n%2==0)
	is_even=true;
	if(n==1){
	cout << "不需要交換" << endl;
	return;
	}

	int temp;
	if(is_even){
		for(int i=0,j=n-1;i-1!=j;i++,j--){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	} else {
		for(int i=0,j=n-1;i!=j;i++,j--){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
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
	srand(time(NULL));
	olist <int>a;
	for(int i=0;i<20;i++)
	a.insert(i,rand()%65536);
	cout << "length: " << a.Length() << endl;
	a.readAll();
	cout << "After reverse(): " << endl;
	a.reverse();
	a.readAll();
	getchar();
}




