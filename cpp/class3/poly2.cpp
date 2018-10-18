#include <iostream>
#include <cmath>
using namespace std;

class Poly{
public:
    Poly();
    Poly(int,int[],int[]);
    void print();
    int eval(int);
    int Leadexp();
    Poly operator+(Poly);
    int gettern();
    int *getcoef();
    int *getexp();

private:
    int tern;
    int ternArray[2][100];
};
int Poly::gettern(){
    return tern;
}
int * Poly::getcoef(){
    int * coef= new int[this->tern];
    for(int i=0;i<tern;i++){
        coef[i] = ternArray[0][i];
    }
    return coef;
}
int * Poly::getexp(){
    int * exp= new int[this->tern];
    for(int i=0;i<tern;i++){
        exp[i] = ternArray[1][i];
    }
    return exp;
}

Poly::Poly(){
    tern = 0;
}

Poly::Poly(int tern,int exp[],int coef[]){
    if(tern < 100){
        this->tern = tern;
        for(int i =0;i<tern;i++){
            ternArray[0][i]=coef[i];
            ternArray[1][i]=exp[i];
        }
    } else {
        cout << "無法建置,超過陣列大小" << endl;
    }
}
void Poly::print(){
    for(int i=0;i<tern;i++){
        cout << ternArray[0][i];
        if(ternArray[1][i] != 0){
            cout << "x";
            if(ternArray[1][i] >=2){
            cout << "^" << ternArray[1][i];
            }
        }
        if(ternArray[1][i] != 0){
            cout << " + ";
        }
    }
    cout << endl;
}
int Poly::eval(int x){
    int total=0;
    for(int i=0;i<tern;i++){
        total += ternArray[0][i] * (pow(x,ternArray[1][i]));
    }
    return total;
}

int Poly::Leadexp(){
    return ternArray[1][0];
}
Poly Poly::operator+(Poly p){
    int apos=0,bpos=0,count=0;
    int *exp; int *coef;
    int newexp[this->tern + p.gettern()]={0}; int newcoef[this->tern + p.gettern()]={0};
    exp = p.getexp();
    coef = p.getcoef();
    for(int i =0;apos < this->tern && bpos < p.gettern(); i++){
        if(ternArray[1][apos] > exp[bpos]){
            newexp[i] = ternArray[1][apos];
            newcoef[i] = ternArray[0][apos];
            apos++;
            count++;
        } else if(ternArray[1][apos] == exp[bpos]){
            newexp[i] = exp[bpos];
            newcoef[i] = ternArray[0][apos] + coef[bpos];
            apos++; bpos++; count++;
        } else {
            newexp[i] = exp[bpos];
            newcoef[i] = coef[bpos];
            bpos++;
            count++;
        }
    }
    Poly b(count,newexp,newcoef);
    delete [] exp;
    delete [] coef;
    return b;
}

int main(){
    int exp[4],coef[4];
    exp[0] = 8; exp[1] = 2; exp[2] = 1; exp[3] = 0;
    coef[0] = 3; coef[1] = 5; coef[2] = 6; coef[3] = 7;
    Poly A(4,exp,coef);
    cout << "A(x) = ";
    A.print();

    exp[0] = 8; exp[1] = 2; exp[2] = 0;
    coef[0] = 7; coef[1] = 5; coef[2] = 9;
    Poly B(3,exp,coef);
    cout << "B(x) = ";
    B.print();

    Poly C = A + B;
    cout << "C(x) = ";
    C.print();

    cout << "A eval(1.0): " << A.eval(1) << endl;
    cout << "B eval(2.0): " << B.eval(2) << endl;
    cout << "C Leadexp(): " << C.Leadexp() << endl;
    cout << "C eval(3.0): " << C.eval(3) << endl;
    system("PAUSE");
}