#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

template < class T >
class Bag
{
public:
	Bag (int bagCapacity = 10);
	~Bag ( );
	
	int Size( ) const;
	bool IsEmpty ( ) const;
	T& Element ( ) const;
	
	void Push (const T&);
	void Pop ();
	void Pop (T * );
	T Top();
	
protected:
	T *array;
	int capacity;
	int top;
};


template < class T >
Bag < T >::Bag (int bagCapacity) : capacity (bagCapacity) {
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T [capacity];
	top = -1;
}

template < class T >
Bag <T>::~Bag ( ) {delete [ ] array;}

template < class T >
void Bag <T>::Push (const T& x) {
	if (capacity == top + 1)
	{
		//ChangeSize1D (array, capacity, 2 * capacity);
		//capacity *= 2;
	}
	array [++top] = x;
}

template <class T>
bool Bag<T> :: IsEmpty() const {
	if(top == -1) return(true);
	else return(false); 
}

template <class T>
T Bag<T> :: Top() {
	return array[top];
}

template < class T >
void Bag < T >::Pop ( T *x) {
	if (IsEmpty ( )) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);
			// �ϰ}�C���
	*x = array[top];
	array [ top-- ].~T ( ) ; // T���Ѻc�l
}

template < class T >
void Bag < T >::Pop () {
	if (IsEmpty ( )) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);
			// �ϰ}�C���
	array [ top-- ].~T ( ) ; // T���Ѻc�l
}

// ...............
template <class T>
class Stack:public Bag<T> {
public:
	Stack(int cap);

};

template <class T>
Stack<T>::Stack(int cap) {
	Bag<T>();
}

// ......queue 
template <class T>
class Queue:public Bag<T> {
	public:
		Queue(int cap);
		void Add(T);
		T Del();
		bool isEmpty();
		bool isFull();
	private:
		int front, rear;
		T *array;
		int capacity;
};

template <class T>
Queue<T>::Queue(int cap) {
	//Bag<T>();
	array = new T[cap];
	capacity = cap;
	front = rear = 0;
}

template <class T>
void Queue<T>::Add(T x) {
	// ? ? ?
	array[++rear] = x;
}

template <class T>
T Queue<T>::Del() {
	// ? ? ?
	return(array[++front]);
}

template <class T>
bool Queue<T>::isEmpty() {
	// ? ? ?
}

// ?? isFull() 

int Eval(char *e) {
	Stack<char> stack(100); // ��l��stack	
	char y1, y2, y3, x;
	int p = 0;
	for (x = e[p++]; x != '$'; x = e[p++]) {
		if (x <= '9' && x >= '0') stack.Push(x);
		else {
			stack.Pop(&y1); stack.Pop(&y2);
			y1 -= 0x30; y2 -= 0x30;
			if (x == '+') y3 = y1 + y2;
			else if (x == '-') y3 = y2 - y1;
			else if (x == '/') y3 = y2 / y1;
			else if (x == '*') y3 = y2 * y1;
			else if (x == '%') y3 = y2 % y1;
			y3 += 0x30;
			stack.Push(y3);

		}

	}
	stack.Pop(&y1);
	y1 -= 0x30;
	cout << endl << "The answer is: " << (int)y1;
	return((int)y1);
}


int main() {
	char s1[] = "83%1453--*+$";
	int i;
	Eval(s1);
	getchar();
}



