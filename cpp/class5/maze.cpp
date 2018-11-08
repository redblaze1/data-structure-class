#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

// ................ stack ...............
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
	
private:
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
		capacity *= 2;
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

// ...................... maze program
enum Direction {N, NE, E, SE, S, SW, W, NW};

struct offset {
	int a, b;
};
struct offset Move[8];

class Items {
	public:
	int x, y, dir;
	Items(int x, int y, int dir);
	Items();
};
Items::Items(int a, int b, int c) {
	x = a;
	y = b;
	dir = c;
}
Items::Items() {
	x = 0; y = 0; dir = 0;
}

const int m=3, p=3;
int mark[m+2][p+2];
//int maze[m+2][p+2];
int maze[][p+2]={{1, 1, 1, 1, 1}, \
				{1, 0, 0, 0, 1}, \
				{1, 0, 1, 1, 1}, \
				{1, 1, 0, 0, 1}, \
				{1, 1, 1, 1, 1}
};

void print_path(Stack<Items> stack) {
	Items temp;
	while(! stack.IsEmpty()) {
		temp = stack.Top();
		stack.Pop();
		cout << temp.x << ":" << temp.y << endl;
	}
}

void Path(const int m, const int p) 				
{ // ��X�g�c���@�Ӹ��|�]�p�G�����ܡ^�F maze[0][i] = maze[m+1][i] =				
 //  maze[j][0] = maze[j][p+1] = 1, 0 ? i ? p+1, 0 ? j ? m+1�C				
	// �q (1, 1) �}�l			
	for(int i = 0; i < m+2; i++) for(int j = 0; j < p+2; j++) mark[m][p] = 0;
	mark[1][1] = 1;			
	Stack<Items> stack(m*p);			
	Items temp(1, 1, 0);			
	     // �]�w temp.x�Btemp.y�B�Ptemp.dir			
	stack.Push(temp);		
	
	Move[0].a = -1; Move[0].b = 0;
	Move[1].a = -1; Move[1].b = 1;
	Move[2].a = 0; Move[2].b = 1;
	Move[3].a = 1; Move[3].b = 1;
	Move[4].a = 1; Move[4].b = 0;
	Move[5].a = 1; Move[5].b = -1;
	Move[6].a = 0; Move[6].b = -1;
	Move[7].a = -1; Move[7].b = -1;
				
	while (!stack.IsEmpty( ))			
	{ // ���|���O�Ū�			
		temp = stack.Top();		
		stack.Pop( );  // �u�X		
		int i = temp.x; int j = temp.y; int d = temp.dir;		
		// dbg
		cout << "one pop" << i << " " << j << " " << d << endl;
		while (d < 8)  // ���e����		
		{		
		// dbg
		cout << "one i & j: " << i << " " << j << " " << d << endl;
			int g = i + Move[d].a; int h = j + Move[d].b;	
			if ((g == m) && (h == p)) { // ��F�X�f	
			    // ��X���|	
				//cout << stack;
				cout << m << ":" << p << endl;
				cout << i << ":" << j << endl;
				// print the path
				while(! stack.IsEmpty()) {
					temp = stack.Top();
					stack.Pop();
					cout << temp.x << ":" << temp.y << endl;
				}
				return;
			}	
			if ((!maze [g ][h]) && (!mark [g ][h])) { // �s��m	
				mark[g][h] = 1;
				temp.x = i; temp.y = j; temp.dir = d+1;
				stack.Push(temp); // �[�J���|
				i = g; j = h; d = 0; // ���� (g, h)
			}
			else d++; // �դU�@�Ӥ�V	
		}		
	}			
	cout << "No path in maze." << endl;
}				


int main() {
	Path(m, p);
	getchar();
}
