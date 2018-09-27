#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>

using namespace std;
void swap(int list[],int n1, int n2){
    list[n1]-=list[n2];
    list[n2]+=list[n1];
    list[n1] = list[n2]-list[n1];
}

void trushbubble(int *list,int n){
    for(;n>0;n--)
        for(int j=0;j<n-1;j++){
            if(list[j]>list[j+1])
            swap(list,j,j+1);
        }
}

int main(){
    srand(time(NULL));
    int a[1000];
    for(int i=0;i<1000;i++){
        a[i]= rand()%100000;
    }
    trushbubble(a,1000);
    for(int i=0;i<1000;i++)
        printf("%d ",a[i]);
    cout << endl;
}