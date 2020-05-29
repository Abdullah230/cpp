#include <iostream>
#include <string>
using namespace std;

class Date { //Initiating class date and declaring variables.
	int day;
	int month;
	int year;
	string dayofweek;
public:
	//Initializing functions
	Date(int day = 0, int month = 0, int year = 2000, string dayofweek = "MON");	
	void set_day(int day);
	void set_month(int month);
	void set_year(int year);
	void set_dayofweek(string dayofweek);
	int get_day();
	int get_month();
	int get_year();
	string get_dayofweek();
	void display();
	void compare_date(Date &date2);
	~Date();		//Initializing destructor.
};
int main(){
	int day, month, year;
	string dayoftheweek;
	//Taking input from the user.
	cout << "Please give the date: ";
	cin >> day;
	cout << "Please give the month: ";
	cin >> month;
	cout << "Please give the year: ";
	cin >> year;
	cout << "Please enter the day of the week: ";
	cin >> dayoftheweek;
	//Substituting values.
	Date date1;
	Date date2(day, month, year, dayoftheweek);
	date1.set_day(24);
	date1.set_month(03);
	date1.set_year(2016);
	date1.display();
	date2.display();
	date1.compare_date(date2);
	system("pause");

}
//Setting constructor.
Date::Date(int day, int month, int year, string dayofweek)
{
	this->day = day;		
	this->month = month;
	this->year = year;
	this->dayofweek = dayofweek;
}	
//Defining functions.
void Date::set_day(int day)
{
	this->day = day;
}	

void Date::set_month(int month)
{
	this->month = month;
}	

void Date::set_year(int year)
{
	this->year = year;
}	

void Date::set_dayofweek(string dayofweek)
{
	this->dayofweek = dayofweek;
}	
int Date::get_day()
{
	return day;
}	

int Date::get_month()
{
	return month;
}	

int Date::get_year()
{
	return year;
}	
string Date::get_dayofweek()
{
	return dayofweek;
}	

void Date::display()
{
	cout << day << "/" << month << "/" << year << " " << dayofweek << endl;
}	
//Defining the destructor.
Date::~Date()
{
	cout << "Day: " << day << ", Month: " << month << ", Year: " << year << endl;
	cout << "Destructor is destroying this object with values." << endl;
}	

void Date::compare_date(Date &date2)
{
	if (year == date2.year && month == date2.month && day == date2.day)
	{
		cout << "Both the dates are the same";
	}
	else {
	if (year > date2.year)	
	{
		cout << "Date 1 is the latest date." << endl;
	}
	else if (year < date2.year)
	{
		cout << "Date 2 is the largest" << endl;
	}
	else{
		if (month > date2.month)	
	{
		cout << "Date 1 is the latest date." << endl;
	}
		else if (month < date2.month)
	{
		cout << "Date 2 is the largest date." << endl;
	}

		else{
			if (day > date2.day){
				cout << "Date 1 is the latest date." << endl;
			}
			else if (day < date2.day)
			{
				cout << "Date 2 is the largest date." << endl;
			}
	}
	}
}
}