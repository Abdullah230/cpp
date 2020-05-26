#include<iostream>
using namespace std;

class task2 //creating class task2
{
private:
	char *pointer; //creating char pointer

public:
	task2()  //default constrctor
	{
		pointer = new char[3];
		pointer[0] = 'a';
		pointer[1] = 'b';
		pointer[2] = 'c';


	}
	task2(char x, char y, char z) //parametrized constructor
	{
		pointer = new char[3];
		pointer[0] = x;
		pointer[1] = y;
		pointer[2] = z;
	}
	task2&operator=(task2&); //calling assignment operator
	friend ostream&operator<<(ostream&, const task2&); //calling display operator
};
ostream&operator<<(ostream&output, const task2&c) //defining display operator
{
	output << c.pointer[0];
	output << c.pointer[1];
	output << c.pointer[2];
	return output;
}
//defining assignment operator
task2& task2::operator=(task2 &obj){
	pointer[0] = obj.pointer[0];
	pointer[1] = obj.pointer[1];
	pointer[2] = obj.pointer[2];
	return *this;
}
int main(void) //writing main function
{
	task2 N, C('p', 'q', 'r');
	N = C; //assigning N to C
	cout << N << endl; //printing
	return 0;
}