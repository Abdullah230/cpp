#include<iostream>
#include<fstream>
#include<string>
#define S 3

using namespace std;

class Books {
	int numofPages;
	string Author;
	int Publicationyear;
public:
	void get_Data() {
		cout << "Number of pages" << endl;
		cin >> numofPages;
		cout << "Name of Author" << endl;
		cin >> Author;
		cout << "Year the book was published in" << endl;
		cin >> Publicationyear;
	}
	void Display() {
		cout << "Number of pages are: " << numofPages << endl;
		cout << "Name of author is: " << Author << endl;
		cout << "Year the book was published in: " << Publicationyear<< endl;
	}
};

void main() {
	//Creating the main function and adding 3 objects of books
	Books inventory[S];
	int user;
	cout << "Enter the number of books(not more than 3): ";
	cin >> user;
	cout << "Please Enter the details of the Books: " << endl;
	for (int i = 0; i < S; i++)
		inventory[i].get_Data();//Entering the details of the books
	cout << "Inventory Management System" << endl;
	int i; char e = 'y';
	for (i = 0; e == 'y'; i++)
	{
		int user0;
		cout << "1.Add a record\n2.Update a record\n3.Display records\n4.Exit\n";
		cin >> user0;

		switch (user0)
		{
			//Setting cases
		case 1:
		{
			//Adding books
			ofstream outfile;
			outfile.open("Liberary.dat", ios::binary | ios::out | ios::in);
			int size = (outfile.tellp() / 32) + (sizeof(inventory));
			outfile.write(reinterpret_cast<char*>(&inventory[size]), sizeof(inventory[size]));
			inventory[size].get_Data();
			break; }


		case 2:
		{
			//Updating books
			ofstream outfile;
			outfile.open("Liberary.dat", ios::out | ios::in | ios::binary);
			cout << "Enter book number you want to update: " << endl;
			int updatebooks;// Number of Books to be updated
			cin >> updatebooks;
			int position = (updatebooks)*sizeof(inventory); //Position of the book to be updated
			outfile.seekp(position, ios::beg);
			outfile.write(reinterpret_cast<char*>(&inventory), sizeof(inventory));
			inventory[updatebooks].get_Data();
			cout << "Thank you for using inventory management system\n ";
			break;
		}


		case 3:
		{
			//Displaying books
			ifstream infile;
			infile.open("Liberary.dat", ios::out | ios::in | ios::binary);
			cout << "Enter the book number you want to display :";
			int displaybook;// Number of book to be displayed
			cin >> displaybook;
			int pos = (displaybook)*sizeof(inventory);//Position of the book to be displayed
			infile.seekg(pos, ios::beg);
			infile.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));
			inventory[displaybook].Display();
			break;
		}

		case 4:
		{
			cout << "Exiting Invenotry Management System " << endl;
			break;
		}
		}
		cout << "Enter y to continue, n to break ";
		cin >> e;
	}
	system("pause");
}
