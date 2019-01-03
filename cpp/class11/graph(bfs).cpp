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

template <class T>
class Graph
{
public:
	virtual ~Graph() {}
	Graph(int n) {N = n; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = 0;}
	void undirected_add(int, int);
	void dfs(int);
	void dfs_driver(int);
	void bfs(int);
	void setcontent(char *);
	void diveapoint(int);

private:
        T g[100][100];
        int visited[100];
        int N;
		char *contents;
		int find[100]={0};
		int count=0;
};

template <class T>
void Graph<T>::undirected_add(int i, int j) {
	g[i][j] = 1;
	g[j][i] = 1;
}

template <class T>
void Graph<T>::dfs_driver(int nd) {
	for(int i = 0; i < N; i++) visited[i] = 0;
	cout << endl;
	dfs(nd);
	cout << endl;
}

template <class T>
void Graph<T>::dfs(int nd) {
	int i;
	visited[nd] = 1;
	cout << contents[nd] << " ";
	for(i = 0; i < N; i++) if(g[nd][i] && ! visited[i]) dfs(i);
}

template <class T>
void Graph<T>::setcontent(char * con) {
	contents = con;
	for(int i = 0; i < N; i++) visited[i] = 0;
}

template <class T>
void Graph<T>::diveapoint(int nnd) {
	for(int i=0;i<N;i++){
		if(g[nnd][i] && ! visited[i]){
			cout << contents[i] << " ";
			visited[i] = 1;
			find[count]=i;
			count++;
			return;
		}
	}
	// return 0;
}

template <class T>
void Graph<T>::bfs(int nd) {
	visited[nd] = 1;
	cout << contents[nd] << " ";
	for(int i=0;i<N;i++){
		if(g[nd][i] && ! visited[i]){
			cout << contents[i] << " ";
			visited[i] = 1;
			find[count] = i;
			count++;
		}
	}
	for(int i=0;i<count;i++){
		diveapoint(find[i]);
	}
}

int main() {
	char content[10] = {'a','m','n','o','p','q','x','y','z'};
    Graph<int> g1(100);
	g1.undirected_add(1, 3);
	g1.undirected_add(3, 4);
	g1.undirected_add(4, 2);
	g1.undirected_add(2, 5);
	g1.undirected_add(1, 7);
	g1.undirected_add(7, 6);
	g1.undirected_add(6, 8);
	g1.setcontent(content);

	g1.bfs(1);
	getchar();
}
