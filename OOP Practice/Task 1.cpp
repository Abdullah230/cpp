#include<iostream>
#include<string>
using namespace std;

class Sandwich {//Initializing class and declaring variables.
	string filling;
	string size;
	double price;
	bool is_ready;
public:
	//Initializing constructors and functions.
	Sandwich();												
	Sandwich(string filling, string size, double price);	
	void set_filling(string filling);
	void set_size(string size);
	void set_price(double price);
	string get_filling();
	string get_size();
	double get_price();
	bool check_status();
	void print_data();
};

int main(){
	string user1, user3;
	double user2;
	Sandwich order1;
	//Taking inut from user.
	cout << "Please enter the filling:";
	cin >> user1;
	order1.set_filling(user1);
	cout << "Please enter the price: ";
	cin >> user2;
	order1.set_price(user2);
	cout << "Please enter the size: ";
	cin >> user3;
	//Inputing values.
	order1.set_size(user3);
	order1.print_data();

	system("pause");
}
//Defining default constructor.
Sandwich::Sandwich()
{
	filling = "None";
	size = "Small";
	price = 00.00;
	is_ready = false;
}	
//Defining parameterized constructor.
Sandwich::Sandwich(string filling, string size, double price)
{
	this->filling = filling;		
	this->size = size;
	this->price = price;
	is_ready = false;
}	
//Defining functions.
void Sandwich::set_filling(string filling)
{
	this->filling = filling;
	is_ready = true;
}	

void Sandwich::set_size(string size)
{
	this->size = size;
}	

void Sandwich::set_price(double price)
{
	this->price = price;
}	

string Sandwich::get_filling()
{
	return filling;
}	

string Sandwich::get_size()
{
	return size;
}	

double Sandwich::get_price()
{
	return price;
}	

bool Sandwich::check_status()
{
	return is_ready;
}	

void Sandwich::print_data()
{
	cout << "---------------Current Status---------------" << endl << "Filling: " << filling << endl << "Size: " << size << endl << "Price: $" << price << endl;
	check_status() ? cout << "Your Sandwich is Ready!" << endl : cout << "Please wait... We are making your sandwich!\n" << endl;
}