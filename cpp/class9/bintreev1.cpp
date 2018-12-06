#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

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
class Stack : public Bag<T> {
public:
	Stack(int cap);

};

template <class T>
Stack<T>::Stack(int cap) {
	Bag<T>();
}



// ......queue 			
template <class T>
class Queue {
public:
	Queue(int cap);
	void Add(T);
	T Del();
	bool isEmpty();
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
	int tmp = rear + 1;
	tmp %= capacity;
	if (tmp == front) cout << "Queue is full";
	else array[rear = tmp] = x;
}

template <class T>
T Queue<T>::Del() {
	if (front == rear) {
		cout << "Queue is empty.";
	}
	else {
		front = (front + 1) % capacity;
		return(array[front]);
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	if (rear == front) return(1);
	else return(0);
}




template <class T> class Tree; //前向宣告
// template <class T> class Stack;		

template <class T>
class TreeNode {
	friend class Tree <T>;
	friend class Stack <T>;
	TreeNode(T e);
private:
	T data;
	TreeNode <T> *leftChild;
	TreeNode <T> *rightChild;
};

template <class T>
TreeNode<T>::TreeNode(T e) {
		data = e;
		leftChild = rightChild = 0;
}

// template <class T>
// class Stack{
// public:

// 	void push(int i, TreeNode<T> *v) {
// 		/* move rear portion */
// 		for (int j = n - 1; j >= i; j--) a[j + 1] = a[j];
// 		/* insert it */
// 		a[i] = v;
// 		n++;
// 	}
// 	void * pop(){
// 		if(n!=0){
// 			n--;
// 		} else {
// 			cout << "裡面沒東西,87" << endl;
// 			return 0;
// 		}
// 		for(int i=n,now=0;now<i;now++) a[now] = a[now+1];
// 	}
// 	bool isemp(){
// 		if(n==0)
// 		return true;
// 		else
// 		return false;
// 	}
// 	TreeNode<T> * Top(){
// 		return a[0];
// 	}
// private:
// 	int n=0;
// 	TreeNode <T> * a[100];
// };
template <class T>
class Tree{
public:
	Tree() { root = 0; }
	void buildTree1();
	void buildTreea();
	void buildTreeb();
	void Inorder(TreeNode<T> *p);
	void NonrecInorder();
	void Preorder(TreeNode<T>*);
	void Levelorder(TreeNode<T> *p);
	void Plot();
	TreeNode<T> *returnRoot() {	return root;};
private:
	TreeNode <T> *root;
};


template <class T>
void Tree <T>::Levelorder(TreeNode<T> *currentNode)
{// 以階序方式走訪二元樹
	Queue < TreeNode <T>*> q(200);
	while (currentNode) {
		cout << currentNode->data << "\t";
		if (currentNode->leftChild) q.Add(currentNode->leftChild);
		if (currentNode->rightChild) q.Add(currentNode->rightChild);
		if (q.isEmpty()) return;
		currentNode = q.Del();
	}
}


template <class T>
void Tree <T>::Inorder(TreeNode <T> *currentNode)
{ // 主程式走訪樹根為currentNode的子樹
	if (currentNode != NULL) {
		Inorder(currentNode->leftChild);
		cout << currentNode->data << "\t";
		Inorder(currentNode->rightChild);
	}
}

template <class T>
void Tree <T>::Preorder(TreeNode <T> *currentNode)
{ // 主程式走訪樹根為currentNode的子樹
	if (currentNode != NULL) {
		cout << currentNode->data << "\t";
		Inorder(currentNode->leftChild);
		Inorder(currentNode->rightChild);
	}
}


struct tmpT {
	TreeNode<char> *nd;
	int v1, v2;
};


#define MAX_LEVEL 6
#define RESOLUTION 2
#define LEFT_MARGINE 1
template <class T>
void Tree<T>::Plot() {
	TreeNode<T> *pt;
	Queue<tmpT> q(100);
	int ord, lev, now_pos, sps, now_lev;
	int idx;
	tmpT ele;
	double s, b;
	
	ele.nd = root;
	ele.v1 = 1;
	ele.v2 = 1;
	q.Add(ele);
	cout << endl;
	now_lev = 1; now_pos = 0;
	while(! q.isEmpty()) {
		ele = q.Del();
		pt = ele.nd; ord = ele.v1; lev = ele.v2;
		if(pt->leftChild) {
			ele.nd = pt->leftChild; ele.v1 = ord*2-1; ele.v2 = lev+1;
			q.Add(ele);
		}
		if(pt->rightChild) {
			ele.nd = pt->rightChild; ele.v1 = ord*2; ele.v2 = lev+1;
			q.Add(ele);
		}
		// * get idx, which counts from MAX_LEVEL (=1)
		idx = MAX_LEVEL - lev + 1;
		// * adjust position (now_pos)
		if(lev > now_lev) {
			cout << endl << endl;
			now_pos = 0;
			now_lev = lev;
		}
		// * calculate spaces (sps)
		s = pow(2.0, (double)(idx-1));
		b = s / 2 - 0.5;
		sps = b + s * (ord-1);
		sps *= RESOLUTION;
		sps += LEFT_MARGINE;
		// * print out sps
		while(now_pos < sps) {
			cout << " "; now_pos ++;
		}
		// * print the data
		cout << pt->data; now_pos ++;
	}
}

template <class T>
void Tree<T>::buildTree1() {
	root = new TreeNode<T>('x');
	root->leftChild = new TreeNode<T>('w');
	root->rightChild = new TreeNode<T>('y');
	root->rightChild->leftChild = new TreeNode<T>('z');
}

template <class T>
void Tree<T>::buildTreea() {
	root = new TreeNode<T>('m');
	root->leftChild = new TreeNode<T>('j');
	root->rightChild = new TreeNode<T>('k');
	root->leftChild->leftChild = new TreeNode<T>('z');
	root->leftChild->rightChild = new TreeNode<T>('p');
}

template <class T>
void Tree<T>::buildTreeb() {
	root = new TreeNode<T>('x');
	root->leftChild = new TreeNode<T>('a');
	root->rightChild = new TreeNode<T>('b');
	root->leftChild->leftChild = new TreeNode<T>('g');
	root->leftChild->rightChild = new TreeNode<T>('d');
	root->leftChild->rightChild->rightChild = new TreeNode<T>('o');

	root->rightChild->leftChild = new TreeNode<T>('h');
	root->rightChild->rightChild = new TreeNode<T>('i');
	root->rightChild->leftChild->leftChild = new TreeNode<T>('p');
	root->rightChild->leftChild->rightChild = new TreeNode<T>('q');
}

template <class T>		
void Tree <T>::NonrecInorder(){		
	Stack < TreeNode < T > * > s;
	TreeNode < T > *currentNode = root;		
	while(1) {		
		while (currentNode) {	
			s.Push(currentNode);
			currentNode = currentNode->leftChild;
		}	
		if (s.IsEmpty()) return;	
		currentNode = s.Top();	
		s.Pop();
		cout << currentNode->data << " ";	
		currentNode = currentNode->rightChild;	
	}
}

int main() {
	cout << "tree1: " << endl;
	Tree<char> tree1;
	tree1.buildTreea();
	// cout << "Levelorder: ";
	// tree1.Levelorder(tree1.returnRoot());
	cout << "Inorder: ";
	tree1.NonrecInorder();

	cout << " \nplot the tree: " << endl;
	tree1.Plot();
	cout << endl;

	cout << "\ntree2: " << endl;
	Tree<char> tree2;
	tree2.buildTreeb();
	cout << "Levelorder: ";
	tree2.Levelorder(tree2.returnRoot());
	// cout << "\nPreorder: ";
	// tree1.Preorder(tree1.returnRoot());
	cout << " \nplot the tree: " << endl;
	tree2.Plot();
	getchar();

}
