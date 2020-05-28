#include <iostream>
#include <string>
using namespace std;
//declaring class
class Student{
private:
	//declarnig variables
	string name;
	int age;
	int *p;
public:
	//declaring default constructor.
	Student(){
		name = "Ali";
		age  = 18;
		p = new int[3];
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
	}
	//declaring copy constructors
	Student(const Student& s0){
		this->name = s0.name;
		this->age = s0.age;
		p = new int[3];
		p[0] = s0.p[0];
		p[1] = s0.p[1];
		p[2] = s0.p[2];
	}
	//set name function
	void set_name(){
		cout << "Please enter a name ";
		cin >> name;
	}


	//age setting function
	void set_age(){
		cout << "Please enter the age of the student ";
		cin >> age;
	}

	//grade setter function
	void set_grades(){
		cout << "Please enter the grades of the student ";
		for (int i = 0; i < 3; i++){
			cin >> p[i];
		}
	}
	//Printing everything
	void show_value(){
		cout << "The name is " << name << ", the age is " << age << " And the adress of the pointer is " << &p << endl;
	}

	//grade showing function
	void show_grades(){
		cout << "The grades are " << p[0] << ", " << p[1] << ", " << p[2] << endl;
	}


};

int main(){
	//Creating two objects
	Student s1;
	Student s2(s1);
	//Showing values
	s1.show_value();
	s2.show_value();
	//Showing grades
	s1.show_grades();
	s2.show_grades();
	//Now setting name of student 1.
	s1.set_name();
	//Now setting age of student 1.
	s1.set_age();
	//Now setting grade of student 1.
	s1.set_grades();
	//Printing everything for student 1.
	s1.show_value();
	//Printing everything for student 2.
	s2.show_value();
	//Showing the grades of student 1.
	s1.show_grades();
	//Showing grades for student 2.
	s2.show_grades();
	system("pause");
}