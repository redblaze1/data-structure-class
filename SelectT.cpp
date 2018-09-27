#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
int count=0;

template<class T>
void printarr(T list[]){
    if (count<2){
    for(int i=0;i<20;i++)
        printf("%d ",list[i]);
    }
    else{
    for(int i=0;i<20;i++)
        cout << list[i] << " ";
    }
    cout << endl;
    count++;
}

template<class T>
void swap(T list[],int n1, int n2){
    list[n1]-=list[n2];
    list[n2]+=list[n1];
    list[n1] = list[n2]-list[n1];
}

template<class T>
void sort( T list[ ], int len){
    int i , j , min ;
	 for ( i = 0 ; i < len - 1 ; i ++ ) {
		 min = i ;
		 for ( j = i + 1 ; j < len ; j ++ )
			 if ( list [ min ] > list [ j ])
				 min = j ;
		 swap ( list [ i ], list [ min ]);
	 }
}

int main(){
    srand(time(NULL));
    int a[20];
    char b[20];
    float c[20];
    for (int i=0;i<20;i++){
        a[i] = rand() % 1000;
        b[i] = rand() % 0xff;
        c[i] = rand() % 500;
    }
    sort(a,20);
    sort(b,20);
    sort(c,20);
    printarr(a);
    printarr(b);
    printarr(c);
}