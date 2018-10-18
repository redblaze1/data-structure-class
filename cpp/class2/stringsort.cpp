#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

void stringswap(string list[],int tran,int traned){
    string temp;
    temp = list[tran];
    list[tran] = list[traned];
    list[traned] = temp;
}

int main(){
    string display[5]={"apple","google","alibaba","amazon","ibm"};
    const char * temp[5];
    for(int i=0;i<5;i++){
        temp[i] = display[i].c_str();
    }
    int point[26];
    for(int i=0;i<5;i++){
        point[temp[i][0] - 0x61]++;
    }
    cout << point[0] << endl;
}