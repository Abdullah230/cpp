#include <iostream>
#include <string>
using namespace std;


class Person{
public:
	int age, numofbooks;
	string name, subject;
	Person(){
		age = 00;
		numofbooks = 00;
		name = "Null";
		subject = "Null";
		cout << "The constructor of person has been called" << endl;
	}

	void set_name(){
		cout << "Please enter the name of the teacher";
		getline(cin, name);
		}

	void set_age(){
		cout << "Enter the name of the teacher";
		cin >> age;
	}

	void set_subject(){
		cout << "Please enter the subject of the teacher";
		getline(cin, subject);
	}

	void set_numofbooks(){
		cout << "Please enter the number of books the author has written";
		cin >> numofbooks;
	}

	Person(int a){
		Person::set_age();
		Person::set_name();
		Person::set_numofbooks();
		Person::set_subject();
		cout << "The constructor of person has been called" << endl;
	}

	~Person(){
		cout << "The destructor of person has been called" << endl;
	}


};


class Teacher: public Person{
private:
	string name, subject;
	int age;
public:

	Teacher(){
		name = "Null";
		age = 00;
		subject = "Null";
		cout << "The constructor of Teacher has been called" << endl;
	}

	Teacher(int a){
		Teacher::set_age();
		Teacher::set_name();
		Teacher::set_subject();
	}



	void set_name(){
		cout << "Please enter the name of the teacher";
		getline(cin, name);
		}

	void set_age(){
		cout << "Enter the name of the teacher";
		cin >> age;
	}

	void set_subject(){
		cout << "Please enter the subject of the teacher";
		getline(cin, subject);
	}

	string get_name(){
		return name;
	}

	string get_subject(){
		return subject;
	}

	int get_age(){
		return age;
	}

	void put_name_teacher(){
		cout << "The name of the teacher is " << Teacher::get_name() << endl; 
	}

	void put_age_teacher(){
		cout << "The age of the teacher is " << Teacher::get_age() << endl;
	}

	void put_subject_teacher(){
		cout << "The subject of thee teacher is " << Teacher::get_subject() << endl;
	}

	~Teacher(){
		cout << "The constructor of teacher has been called" << endl;
	}

};

class Author: public Person{
private:
	string name, subject;
	int age, numofbooks;
public:

	Author(){
		name = "Null";
		subject = "Null";
		age = 00;
		numofbooks = 00;
		cout << "The constructor of Author has been called" << endl;
	}

	Author(int a){
		Author::set_age();
		Author::set_name();
		Author::set_numofbooks();
		Author::set_subject();
	}

	void set_name(){
		cout << "Please enter the name of the author";
		getline(cin, name);
	}

	void set_subject(){
		cout << "Please enter the subject of the author";
		getline(cin, subject);
	}

	void set_age(){
		cout << "Please enter the age o thee author";
		cin >> age;
	}

	void set_numofbooks(){
		cout << "Please enter the number of books the author has written";
		cin >> numofbooks;
	}

	string get_name(){
		return name;
	}

	string get_subject(){
		return subject;
	}

	int get_age(){
		return age;
	}

	int get_numofbooks(){
		return numofbooks;
	}

	void put_numofbooks_Author(){
		cout << "The number of books written by the author are " << Author::get_numofbooks() << endl;
	}

	void put_subject_author(){
		cout << "The subject of the author is " << Author::get_subject() << endl;
	}

	void put_age_author(){
		cout << "The age of the author is " << Author::get_age() << endl;
	}

	void put_name_author(){
		cout << "The name of the Author is " << Author::get_name() << endl;
	}

	~Author(){
		cout << "The destructor of Author has been called" << endl;
	}
};

class Scholar: public Teacher, public Author{
private:
	string universityname, department;
	int numberofclasses;
public:

	Scholar(){
		universityname = "NUll";
		department = "Null";
		numberofclasses = 00;
		cout << "The constructor of scholar has been called";
	}

	Scholar(int a){
		if(a == 1){
		Teacher::set_age();
		Teacher::set_name();
		Teacher::set_subject();
		set_universityname();
		set_department();
		set_numberofclasses();
		}

		else{
			Author::set_age();
			Author::set_name();
			Author::set_numofbooks();
			Author::set_subject();
			set_department();
			set_universityname();
			set_numberofclasses();
		}
		
	}

	void put_department(){
		cout << "The name of the department is " << Scholar::get_department() << endl;
	}

	void put_university(){
		cout << "The name of the university is " << Scholar::get_universityname() << endl;
	}

	void put_numberofclasses(){
		cout << "The number of classes of the scholar are " << Scholar::get_numberofclasses() << endl;
	}

	string get_universityname(){
		return universityname;
	}

	string get_department(){
		return department;
	}

	int get_numberofclasses(){
		return numberofclasses;
	}

	void set_universityname(){
		cout << "Enter the name of the university" << endl;
		getline(cin, universityname);
	}

	void set_department(){
		cout << "Enter the name of the department" << endl;
		getline(cin, department);
	}

	void set_numberofclasses(){
		cout << "Please enter the number of classes" << endl;
		cin >> numberofclasses;
	}

	void print_everything(){
		put_age_author();
		put_age_teacher();
		put_name_author();
		put_name_teacher();
		put_numofbooks_Author();
		put_subject_author();
		put_subject_author();
		put_subject_teacher();
		put_university();
		put_department();
		put_numberofclasses();
	}

	~Scholar()
		{
			cout<<"The Destructor of Scholar has been called " << endl;
	}
};

int main(){
	Scholar s;
	s.print_everything();

}
