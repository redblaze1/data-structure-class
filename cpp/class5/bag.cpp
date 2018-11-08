#include <iostream>			
#include <ctime>			
#include <cstdlib>			
#include <stdio.h>			

using namespace std;

template < class T >
class Bag
{
public:
	Bag(int bagCapacity = 10);
	~Bag();

	int Size() const;
	bool IsEmpty() const;
	T& Element() const;

	void Push(const T&);
	void Pop();
	void Pop(T *);
	T Top();

private:
	T *array;
	int capacity;   // �̤j�e�q 		
	int top;
};


template < class T >
Bag < T >::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template < class T >
Bag <T>::~Bag() { delete[] array; }

template < class T >
void Bag <T>::Push(const T& x) {
	if (capacity == top + 1)
	{
		//ChangeSize1D (array, capacity, 2 * capacity);	
		capacity *= 2;
	}
	array[++top] = x;
}

template <class T>
bool Bag<T> ::IsEmpty() const {
	if (top == -1) return(true);
	else return(false);
}

template <class T>
T Bag<T> ::Top() {
	return array[top];
}

template < class T >
void Bag < T >::Pop(T *x) {
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);		
	// �ϰ}�C���
	*x = array[top];
	array[top--].~T(); // T���Ѻc�l		
}

template < class T >
void Bag < T >::Pop() {
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);		
	// �ϰ}�C���
	array[top--].~T(); // T���Ѻc�l		
}

// ...............			
template <class T>
class Stack :public Bag<T> {
public:
	Stack(int cap);

};

template <class T>
Stack<T>::Stack(int cap) {
	Bag<T>();
}

int main() {
	int v;
	float fv;
	Bag<int> a(100);
	try {
		a.Push(1);
		a.Push(2);
		a.Pop(&v);
		cout << v << "\t";
		a.Pop(&v);
		cout << v << "\t";
		Stack<float> b(100);
		b.Push(3.14159);

		// top() test	
		cout << b.Top() << "\t";

		b.Pop(&fv);
		cout << fv << "\t";
		if (!b.IsEmpty()) {
			b.Pop(&fv);
			cout << fv << "\t";
		}
	}
	catch (char * msg) {
		cout << msg << endl;
	}

	// system("pause");
}

