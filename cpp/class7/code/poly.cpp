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
    polynomial();    // termArray[100] �ݰt�m, capacity = 100, terms = 0;		
    polynomial Add(polynomial);		
    void NewTerm(float coef, int exp);		
};
*/		


class Polynomial {
	private:
	term termArray[100];
	int terms, capacity;

//  p(x) = �F�@�� <ei�Aai> �����ǹ蠟���X�A
// �䤤ai�O�@�ӫD�s�� float �Y�ƦӬOei�@�ӫD�t����ƫ��ơC
public:
	Polynomial();
	// �إߦh����p(x) = 0�C

	Polynomial Add(Polynomial poly);
	// �^�� *this�Ppoly��Ӧh�������M�C

	Polynomial Mult(Polynomial poly);
	// �^�� *this�Ppoly��Ӧh�������n�C

	float Eval(float f );
	// �D�X��h���� *this�� f�ɪ��ȨåB�^�ǥ������G�C

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
{// �^�Ǧh���� *this�Pb���M
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
  // �� *this���ѤU�������[�i��
  for ( ; aPos < terms ; aPos++)
    c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
  // �� b(x) ���ѤU�������[�i��
  for ( ; bPos < b.terms ; bPos++)
    c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
  return c;
}



void Polynomial::NewTerm(const float theCoeff, const int theExp)
{// �btermArray�����ݥ[�J�@�ӷs��
	/*
    if (terms == capacity)
    {// �NtermArray���e�q�[��
        capacity *= 2;
        term *temp = new term[capacity];  // �s�}�C
        copy(termArray, termArray + terms, temp);
        delete [] termArray ;              // �����ª��O����
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



