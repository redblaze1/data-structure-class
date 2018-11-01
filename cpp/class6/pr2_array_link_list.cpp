#include<iostream>
using namespace std;

class array_link_list {	
private:	
	char data[100][4];
	int link[100];
	int first;
public:	
    
	array_link_list();
    array_link_list(bool);     
	void build_original_list(); // 須建構原來的串列
	void print();
	void insert_Gat();
};

array_link_list::array_link_list(){
    first =1;
}

array_link_list::array_link_list(bool already){
    first = 5;

	data[2][0] = 'f'; data[2][1] = 'a'; data[2][2] = 't'; data[2][3] = '$';
	link[2] = 4;

	data[3][0] = 'c'; data[3][1] = 'a'; data[3][2] = 't'; data[3][3] = '$';
	link[3] = 6;

	data[4][0] = 'h'; data[4][1] = 'a'; data[4][2] = 't'; data[4][3] = '$';
	link[4] = -1;

	data[5][0] = 'b'; data[5][1] = 'a'; data[5][2] = 't'; data[5][3] = '$';
	link[5] = 3;

	data[6][0] = 'e'; data[6][1] = 'a'; data[6][2] = 't'; data[6][3] = '$';
	link[6] = 2;

	data[8][0] = 'g'; data[8][1] = 'a'; data[8][2] = 't'; data[8][3] = '$';
}

void array_link_list::build_original_list(){
    first = 5;

	data[2][0] = 'f'; data[2][1] = 'a'; data[2][2] = 't'; data[2][3] = '$';
	link[2] = 4;

	data[3][0] = 'c'; data[3][1] = 'a'; data[3][2] = 't'; data[3][3] = '$';
	link[3] = 6;

	data[4][0] = 'h'; data[4][1] = 'a'; data[4][2] = 't'; data[4][3] = '$';
	link[4] = -1;

	data[5][0] = 'b'; data[5][1] = 'a'; data[5][2] = 't'; data[5][3] = '$';
	link[5] = 3;

	data[6][0] = 'e'; data[6][1] = 'a'; data[6][2] = 't'; data[6][3] = '$';
	link[6] = 2;

    data[7][0] = ' '; data[7][1] = ' '; data[7][2] = ' '; data[7][3] = '$';
	link[7] = 0;

    data[8][0] = 'g'; data[8][1] = 'a'; data[8][2] = 't'; data[8][3] = '$';
	link[8] = 0;
}

void array_link_list::print(){
	cout << "first= " << this->first << endl;
    cout << "index \t data\tlink" << endl;
    cout << "一一一一一一一一一一一" << endl;
    for(int i=2;i<9;i++){
        if(!(link[i]+1)){
            cout << "|  " << i << "  " << "|  " << data[i][0] << data[i][1] << data[i][2] <<"  |  " << link[i] <<"   |" << endl;
            continue;
        }
        cout << "|  " << i << "  " << "|  " << data[i][0] << data[i][1] << data[i][2] <<"  |   " << link[i] <<"   |" << endl;
    }
    cout << "一一一一一一一一一一一" << endl;
	cout << "邏輯圖: ";

	for(int i=this->first;i+1;){
		cout << data[i][0] << data[i][1] << data[i][2];
		if (link[i] != -1)
		cout << "->"; 
		i = link[i];
	}
	cout << endl;
}
void array_link_list::insert_Gat(){
	link[8] = link[2];
	link[2] = 8;   // 8是gat位址
}

int main(){
    array_link_list test;
    test.build_original_list();
    test.print();

	cout << endl;
	test.insert_Gat();
	test.print();
}
