#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main(int argc,char* argv[]){
    srand(time(NULL));
    int a = rand(),b;
    vector<string> st;
    int num=8,arg,count=1;
    for (arg = 1; arg < argc; arg++){
        unsigned int c;
        if ((0 == strcmp(argv[arg], "-l"))){
            arg++;
            sscanf(argv[arg], "%x", &c);
            num = (int)c;
        } else if ((0 == strcmp(argv[arg], "-n"))){
            arg++;
            sscanf(argv[arg], "%x", &c);
            count = (int)c;
        }
    }
    for(int co = 0;co<count;co++){
        for(int i=0;i<num;i++){
            if(i%4==0)
                a = rand();
            b = (a & (0xff000000 >> (i * 8))) >> (24 - 8*i);
            b = (b % 0x5e) + 0x20;
            // printf("b: %x\n",b);
            st[co]+=b;
        }
        cout << st[co] << endl;
    }
}
