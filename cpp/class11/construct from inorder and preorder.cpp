#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;
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
	if(tmp == front) cout << "Queue is full";
	else array[rear = tmp] = x;
}

template <class T>
T Queue<T>::Del() {
	if(front == rear) {
		cout << "Queue is empty.";	
	}
	else {
		front = (front + 1) % capacity;
		return(array[front]);
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	if(rear == front) return(1);
	else return(0);
}

// ***** tree
template <class T> class Tree; //�e�V�ŧi			

template <class T>
class TreeNode {
	friend class Tree <T>;
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

template <class T>
class Tree{
public:
	Tree() { root = 0; }
	void Inorder(TreeNode<T> *p);
	void Insert(T e);
	void Plot();
	void Construct(char *, char *);
	TreeNode<T> * Cons(char *, char *);
	int notEmpty();
	TreeNode<T> *returnRoot() {	return root;};
private:
	TreeNode <T> *root;
};

template <class T>
void Tree<T>::Construct(char *preo, char *ino) {
	root = Cons(preo, ino);
}

template <class T>
TreeNode<T>* Tree<T>::Cons(char *preo, char *ino) {
	TreeNode<T> *leftSubtree, *rightSubtree, *tmp;
	int len;
	int left_len, right_len;
	char root_char = preo[0];
	int i;
	char *left_preo, *right_preo, *left_ino, *right_ino;
	for(len = 0; preo[len] != '\0'; len++);
	if(len == 0) return NULL;
	for(i = 0; i < len && root_char != ino[i]; i++);
	left_len = i; 
	right_len = len - left_len - 1;
	//* for left subtree
	left_preo = new char[left_len+1];
	for(i = 0; i < left_len; i++) left_preo[i] = preo[i+1];
	left_preo[i] = '\0';
	left_ino = new char[left_len+1];
	for(i = 0; i < left_len; i++) left_ino[i] = ino[i];
	left_preo[i] = '\0';
	leftSubtree = Cons(left_preo, left_ino);
	//* for right subtree
	right_preo = new char[right_len+1];
	for(i = 0; i < right_len; i++) right_preo[i] = preo[i+left_len+1];
	right_preo[i] = '\0';
	right_ino = new char[right_len+1];
	for(i = 0; i < right_len; i++) right_ino[i] = ino[i+left_len+1];
	right_preo[i] = '\0';
	rightSubtree = Cons(right_preo, right_ino);
	tmp = new TreeNode<char>(root_char);
	tmp->leftChild = leftSubtree;
	tmp->rightChild = rightSubtree;
	return tmp;
}

template <class T>
void Tree <T>::Inorder(TreeNode <T> *currentNode)
{ // �D�{�����X��ڬ�currentNode���l��			
	if (currentNode != NULL) {
		Inorder(currentNode->leftChild);
		cout << currentNode->data << "\t";
		Inorder(currentNode->rightChild);
	}
}

struct tmpT {
	TreeNode<char> *nd;
	int v1, v2;
};

#define MAX_LEVEL 6
#define RESOLUTION 2
#define LEFT_MARGINE 8
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
void Tree<T>::Insert(T e) {
	TreeNode<T> *tmp = new TreeNode<T>(e), *pt;
	if (!root) root = tmp;
	else {
		pt = root;
		do {
			if (tmp->data <= pt->data) {
				if (!pt->leftChild) {
					pt->leftChild = tmp;
					break;
				}
				pt = pt->leftChild;
			}
			else {
				if (!pt->rightChild) {
					pt->rightChild = tmp;
					break;
				}
				pt = pt->rightChild;
			}
		} while (1);

	}
}

int main() {
	Tree<char> tree1;
	char *preo, *ino;

	preo = "abcdwze";
	ino = "bawdzce";
	//preo = "abc";
	//ino = "bac";
	tree1.Construct(preo, ino);
	tree1.Plot();
	getchar();
}
