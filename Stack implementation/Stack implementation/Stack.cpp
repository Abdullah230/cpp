#include<iostream>
#include <string>
#include <conio.h>
using namespace std;

class stack
{
public:

	char* array;
	int top;
	char element;
	int SIZE;

	stack(int a)//Initializing data members of class stack
	{
		SIZE = a;
		array = new char[SIZE];
		element = 0;
		top = -1;
	}

	bool isfull()//Function to check if stack is full
	{
		return top == SIZE - 1;
	}

	bool isempty()//Function to check if stack is empty
	{
		return top < 0;
	}

	void Push(char el)//pushes an element on the top of stack
	{
		if (!isfull())
		{
			array[++top] = el;
		}

	}

	char pop()//removes the top element of the stack
	{
		if (!isempty())
		{
			element = array[top];
			array[top--] = 0;
		}
		return element;
	}

};

int main()
{
	char symb;
	string exp;
	cout << "Enter expression: ";
	cin >> exp;

	stack s1(exp.length()), s2(exp.length());	//object of class stack with array equal to length of input string
	bool valid = true;

	for (int i = 0; i < exp.length(); i++)	//checking the string for balanced braces
	{
		symb = exp[i];

		if (symb == '(' || symb == '[' || symb == '{')	//if symbol is opening brackets it is pushed into stack 
		{
			s1.Push(symb);	//pushes braces to stack s1
			s2.Push(i + 1);	// position of braces to stack s2
		}

		if (symb == ')' || symb == ']' || symb == '}')	//if symbol is opening bracket
		{
			if (s1.isempty())	//if stack is empty
			{
				valid = false;
				cout << "String empty" << endl;
			}
			else
			{
				char x = s1.pop();	//if stack is not empty pop top element from string

				if (!((symb == ')' && x == '(') || (symb == ']' && x == '[') || (symb == '}' && x == '{')))	//checking if symbol does not match with element popped
				{
					cout << "Error due to unmatched braces " << x << " at character # " << (int)s2.pop() << endl;
					valid = false;

				}
				else
					s2.pop();
			}//end of else
		}

	}//end of for loop

	while (!s1.isempty())	//prints out all unclosed braces with position
	{
		valid = false;
		cout << "Error due to unclosed brace " << s1.pop() << " at character # " << (int)s2.pop() << endl;
	}

	if (valid)	//prints whether expression is correct or not
		cout << "This expression is CORRECT." << endl;
	else
		cout << "This expression is NOT CORRECT." << endl;

	system("PAUSE");
}
