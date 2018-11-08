#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class term {
	public:
	int exp;
	float coef;
};

/*
class polynomial {		
  private:		
    Term *termArray;		
    int capacity;		
    int terms;		
  public:		
    polynomial();    // termArray[100] 需配置, capacity = 100, terms = 0;		
    polynomial Add(polynomial);		
    void NewTerm(float coef, int exp);		
};
*/		


class Polynomial {
	private:
	term termArray[100];
	int terms, capacity;

//  p(x) = ；一個 <ei，ai> 的有序對之集合，
// 其中ai是一個非零的 float 係數而是ei一個非負的整數指數。
public:
	Polynomial();
	// 建立多項式p(x) = 0。

	Polynomial Add(Polynomial poly);
	// 回傳 *this與poly兩個多項式之和。

	Polynomial Mult(Polynomial poly);
	// 回傳 *this與poly兩個多項式之積。

	float Eval(float f );
	// 求出當多項式 *this為 f時的值並且回傳它的結果。

	void NewTerm(float coef, int exp);
	int LeadExp();

	void Print();
};

Polynomial::Polynomial() {
	capacity = 100;
	terms = 0;
}

void Polynomial::Print() {
	for(int i = 0; i < terms; i++) {
		if(i > 0) cout << " " << (termArray[i].coef > 0 ? '+' : '-') << " ";
		cout << abs(termArray[i].coef) << "x^" << termArray[i].exp;
	}
	cout << endl;
}

Polynomial Polynomial::Add(Polynomial b)
{// 回傳多項式 *this與b的和
  Polynomial c;
  int aPos = 0, bPos = 0;
  while ((aPos < terms) && (bPos < b.terms))
    if (termArray[aPos].exp == b.termArray[bPos].exp) {
        float t = termArray[aPos].coef + b.termArray[bPos].coef;
        if (t) c.NewTerm (t, termArray[aPos].exp);
         aPos++; bPos++;
    }
    else if (termArray[aPos].exp < b.termArray[bPos].exp) {
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
        bPos++;
    }
    else {
        c.NewTerm(termArray[aPos].coef,termArray[aPos].exp);
        aPos++;
    }
  // 把 *this中剩下的項給加進來
  for ( ; aPos < terms ; aPos++)
    c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
  // 把 b(x) 中剩下的項給加進來
  for ( ; bPos < b.terms ; bPos++)
    c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
  return c;
}



void Polynomial::NewTerm(const float theCoeff, const int theExp)
{// 在termArray的末端加入一個新項
	/*
    if (terms == capacity)
    {// 將termArray的容量加倍
        capacity *= 2;
        term *temp = new term[capacity];  // 新陣列
        copy(termArray, termArray + terms, temp);
        delete [] termArray ;              // 釋放舊的記憶體
        termArray = temp;
    }
    */
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}

int main() {
	Polynomial A, B, C;
	A.NewTerm(4.0, 3);
	A.NewTerm(-4.3, 2);
	A.NewTerm(3.0, 1);
	A.NewTerm(2.0, 0);
	B.NewTerm(1.0, 3);
	A.Print();
	B.Print();
	C = B.Add(A);
	C.Print();
	system("pause");
}



