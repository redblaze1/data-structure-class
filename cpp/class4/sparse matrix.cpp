#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class term {
	friend class SparseMatrix;
	private:
	int row, col, value;
};
class SparseMatrix
{// �T���աA<�C�A��A��>�A�����X�A�䤤�C�P�欰�D�t��ơA
// �åB�����զX�O�ߤ@���F�Ȥ]�O�Ӿ�ơC
	int cols, rows, terms, capacity;
	term *smArray;
public:
    SparseMatrix(int r, int c,int t);
    // �غc�l�禡�A�إߤ@�Ӧ�r�Cc��åB�㦳��t�ӫD�s�����e�q

    SparseMatrix Transpose( );
    //�^�ǱN *this���C�ӤT���ժ���P�C�洫�᪺SparseMatrix
    SparseMatrix FastTranspose( );

    SparseMatrix Add(SparseMatrix b);
    // �p�G *this�Mb�����פ@�ˡA����N��۹����������ۥ[�A
    // ��Y�A�㦳�ۦP�C�M�檺�ȷ|�Q�^�ǡF�_�h���ܥ�X�ҥ~�C

    SparseMatrix Multiply(int);
    // �p�G*this������ƩMb�����C�Ƥ@�˦h���ܡA����^�Ǫ��x�}d�N�O *this�Mb
    //�]�̾�d[i][j]=�U(a[i][k]�Db[k][j]�A�䤤d[i][j]�O�� (i, j) �Ӥ����^�ۭ������G�Ck���d��
    // �q0��*this����ƴ�1�F�p�G���@�˦h���ܡA����N��X�ҥ~�C
    void StoreSum(const int sum, const int r, const int c);
    void print();
};



SparseMatrix SparseMatrix::Transpose( )
{// �^��*this����m�x�}
  SparseMatrix b(cols , rows , terms); // b.smArray���e�q��terms
  b.terms = this->terms;
  if (terms > 0)
  {// �D�s���x�}
    int currentB = 0;
    for (int c = 0 ; c < cols ; c++){  // �ھڦ����m
      for (int i = 0 ; i < terms ; i++){
      // �M��ò��ʦb��c�檺��
        if (smArray[i].col == c){
          b.smArray[currentB].row = c;
          b.smArray[currentB].col = smArray[i].row;
          b.smArray[currentB++].value = smArray[i].value;
        }
      }
    }
  } // if (terms > 0) ����
  return b;
}


void SparseMatrix::StoreSum(const int sum, const int r, const int c)
{// �p�Gsum != 0�A���򥦥H�ΩM���@�_�Ƕi�Ӫ��Cr�B��c����m�N�s�� *this��
// �̫�@�Ӷ�
    if (sum != 0) {
        //if (terms == capacity)
        //    ChangeSize1D(2*capacity); // �[���e�q
        smArray[terms].row = r;
        smArray[terms].col = c;
        smArray[terms++].value = sum;
    }
}

SparseMatrix::SparseMatrix(int r, int c, int t) {
	rows = r;
	cols = c;
	capacity = t;
	terms = 0;  // modified
	smArray = new term[t];
}


void SparseMatrix::print() {
	int i, j, sum, t;
	for(i = 0; i < rows; i++) {
		cout << endl;
		for(j = 0; j < cols; j++) {
			sum = 0;
			for(t = 0; t < terms; t++) if(smArray[t].row == i && smArray[t].col == j) sum += smArray[t].value;
			cout << sum << "\t";
		}
	}	
}
  SparseMatrix SparseMatrix::Multiply(int d){
    SparseMatrix b(cols , rows , terms);
    b.terms = this->terms;
    if (terms > 0){
    int currentB = 0;
    for (int c = 0 ; c < cols ; c++){
      for (int i = 0 ; i < terms ; i++){
        if (smArray[i].col == c){
          b.smArray[currentB].row = smArray[i].row;
          b.smArray[currentB].col = smArray[i].col;
          b.smArray[currentB++].value = smArray[i].value*3;
        }
      }
    }
    }
  return b;
  }

int main() {
	SparseMatrix a(3, 3, 10);
	a.StoreSum(3,0,0) ;
	a.StoreSum(5, 0, 2);
	a.StoreSum(17, 1, 0);
  a.StoreSum(7, 1, 1);
  a.StoreSum(55, 2, 1);
  a.StoreSum(9, 2, 2);
	a.print();
  cout << endl;
  a.Transpose().print();
  cout << endl;
  a.Multiply(3).print();
	getchar();
}

