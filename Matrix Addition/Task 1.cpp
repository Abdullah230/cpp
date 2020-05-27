#include <iostream>
using namespace std;

class Matrix{
private:
	double a1, a2, a3, a4;
public:
	void operator+(Matrix& m1){ //overloading operator
		this->a1 = this->a1 + m1.a1;
		this->a2 = this->a2 + m1.a2;
		this->a3 = this->a3 + m1.a3;
		this->a4 = this->a4 + m1.a4;
	}

	void set_matrix(){ //Creating setter function
		cout << "Please enter the elements in order of a1, a2, a3, a4 respectively" << endl;
		cin >> a1 >> a2 >> a3 >> a4;
	}
	//Creating getter functions
	int get_a1(){ 
		return a1;
	}

	int get_a2(){
		return a2;
	}

	int get_a3(){
		return a3;
	}

	int get_a4(){
		return a4;
	}
	// Creating print function
	void print_matrix(){
		cout << "The matrix is " << a1 << "   " << a2 << "   " << endl << "              " << a3 << "   " << a4;
	}
};

void main(){
	Matrix m1, m2;//Creating two objects
	m1.set_matrix();//Setting Matrices
	m2.set_matrix();//Setting matrices
	cout << "Now adding m2 to m1" << endl;
	m1 + m2;//Adding matrices
	m1.print_matrix();//Printing the matrix
	cout << endl;
	int test = 23, test2 = 20;
	system("pause");
}