#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

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

template <class T> class Graph;

template <class T>
class Vertex {
friend class Graph<T>;
  Vertex(int e);
  Vertex(int e, int w);
private:
  int data;
  int weight;
  Vertex<T> *link;
};
template <class T>
Vertex<T>::Vertex(int d) {
	data = d;
	link = 0;
}

template <class T>
Vertex<T>::Vertex(int d, int w) {
	data = d;
	link = 0;
	weight = w;
}

template <class T>
class Graph
{
public:
	virtual ~Graph() {}
	Graph(int n) {N = n; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = 0; vertexN = 0; for(int i = 0; i < n; i++) adlist[i] = 0;}
	void undirected_add(int, int);
	void adlist_add(int, int);
	void dir_adlist_add(int, int, int);
	void print_list(int);
	void adlist_dfs(int);
	void adlist_dfs_driver(int);
	void setcontent(char *);
private:
        T g[100][100];
        Vertex<T> *adlist[100];
        int visited[100];
        int N;
        int vertexN;
		int count[100];
		char *contents;
		int find[100]={0};
		int count2=0;
};


template <class T>
void Graph<T>::adlist_add(int i, int j) {
	Vertex<T> *tmp = new Vertex<T>(j), *tmp2 = new Vertex<T>(i);
	tmp->link = adlist[i];
	adlist[i] = tmp;
	tmp2->link = adlist[j];
	adlist[j] = tmp2;
}

template <class T>
void Graph<T>::dir_adlist_add(int i, int j, int weight) {
	Vertex<T> *tmp = new Vertex<T>(j, weight);
	tmp->link = adlist[i];
	adlist[i] = tmp;
}

template <class T>
void Graph<T>::print_list(int p) {
	cout << endl << "print a line[" << contents[p] << "]:";
	for(Vertex<T> *pt = adlist[p]; pt != 0; pt = pt->link) cout << pt->data << "  ";
}
template <class T>
void Graph<T>::undirected_add(int i, int j) {
	g[i][j] = 1;
	g[j][i] = 1;
}

template <class T>
void Graph<T>::setcontent(char * con) {
	contents = con;
	for(int i = 0; i < N; i++) visited[i] = 0;
}

template <class T>
void Graph<T>::adlist_dfs_driver(int nd) {
	for(int i = 0; i < N; i++) visited[i] = 0;
	cout << endl;
	adlist_dfs(nd);
	cout << endl;
}

template <class T>
void Graph<T>::adlist_dfs(int nd) {
	int i;
	visited[nd] = 1;
	cout << contents[nd] << " ";
	for(Vertex<T> *pt = adlist[nd]; pt != 0; pt = pt->link) if(!visited[pt->data])adlist_dfs(pt->data);
}

int main() {
    Graph<int> g1(100);
	char content[10] = {'a','m','n','o','p','q','x','y','z'};
	g1.setcontent(content);
    g1.adlist_add(1, 3);
    g1.adlist_add(1, 7);
	g1.adlist_add(2, 4);
    g1.adlist_add(2, 5);
	g1.adlist_add(6, 8);
	g1.adlist_add(6, 7);
	g1.adlist_add(3, 4);
	g1.adlist_add(0, 7);
	g1.adlist_dfs_driver(6);

    /*
	g1.undirected_add(2, 2);
	g1.undirected_add(2, 3);
	g1.undirected_add(3, 4);
	g1.undirected_add(4, 5);
	g1.dfs_driver(2);
	*/
	getchar();
}

