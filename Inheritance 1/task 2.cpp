#include <iostream>              //header files
#include <string>
#include <conio.h>
#define NUM 50
using namespace std;
class vehicle                                 //Base class
{
	int ID, model_number, stock;
	string color;
public:
	void set_stock(int num);
	void set_ID(int id);
	void set_model_number(int num);
	void set_color(string colour);
	int get_ID();
	int get_model_number();
	string get_color();
	int get_stock();
	void print();
};
void vehicle::set_stock(int num)
{
	stock = num;
}
int vehicle::get_stock()
{
	return stock;
}
void vehicle::print()
{
	cout << "Vehicle ID: " << ID << endl;
	cout << "Vehicle Model Number: " << model_number << endl;
	cout << "Vehicle Color: " << color << endl;
	cout << "Stock: " << stock << endl;
}
void vehicle::set_ID(int id)
{
	ID = id;
}
void vehicle::set_model_number(int num)
{
	model_number = num;
}
void vehicle::set_color(string color)
{
	this->color = color;
}
int vehicle::get_ID()
{
	return ID;
}
int vehicle::get_model_number()
{
	return model_number;
}
string vehicle::get_color()
{
	return color;
}
class car : public vehicle                                  //child class
{
	int num_of_doors;
	string type;
public:
	car() { set_ID(-1); }
	~car();
	car(int id, int num, string clr, int doors, int stock, string type) :num_of_doors(doors), type(type) {
		set_ID(id);
		set_model_number(num);
		set_color(clr);
		set_stock(stock);
	}
	void set_num_of_doors(int num);
	void set_type(string type);
	string get_type();
	int get_num_of_doors();
	void print();
};
car::~car()
{
	cout << "The selected vehicle was deleted!" << endl;
	system("pause");
}
void car::set_type(string type)
{
	this->type = type;
}
string car::get_type()
{
	return type;
}
void car::set_num_of_doors(int num)
{
	num_of_doors = num;
}
int car::get_num_of_doors()
{
	return num_of_doors;
}
void car::print()
{
	cout << "Type: " << type << endl;
	vehicle::print();
	cout << "Car Number of doors: " << num_of_doors << endl << endl << endl;
}
class toyota :public car
{
};
class chevrolet :public car
{
};
class bus : public vehicle
{
	string engine, transmission;
	int passengers;
public:
	bus() { set_ID(-1); }
	~bus();
	bus(int id, string clr, string eng, string t_mission, int people, int stock) :engine(eng), transmission(t_mission), passengers(people) {
		set_ID(id);
		set_color(clr);
		set_stock(stock);
	}
	void set_engine(string engine);
	void set_transmission(string transmission);
	void set_passengers(int passengers);
	string get_engine();
	string get_transmission();
	int get_passengers();
	void print();
};
bus::~bus()
{
	cout << "The selected vehicle was deleted!" << endl;
	system("pause");
}
void bus::set_engine(string engine)
{
	this->engine = engine;
}
void bus::set_transmission(string transmission)
{
	this->transmission = transmission;
}
void bus::set_passengers(int passengers)
{
	this->passengers = passengers;
}
string bus::get_engine()
{
	return engine;
}
string bus::get_transmission()
{
	return transmission;
}
int bus::get_passengers()
{
	return passengers;
}
void bus::print()
{
	vehicle::print();
	cout << "Bus engine: " << engine << endl;
	cout << "Number of passengers: " << passengers << endl;
	cout << "Bus transmission: " << transmission << endl << endl << endl;
}
class truck : public vehicle                               //child class
{
	int tow_capacity;
	string cab_size;
public:
	truck() { set_ID(-1); }
	~truck();
	truck(int id, int num, string clr, int tc, string cs, int stock) :tow_capacity(tc), cab_size(cs) {
		set_ID(id);
		set_model_number(num);
		set_color(clr);
		set_stock(stock);
	}
	void set_tow_capacity(int num);
	void set_cab_size(string size);
	int get_tow_capacity();
	string get_cab_size();
	void print();
};
truck::~truck()
{
	cout << "The selected vehicle was deleted!" << endl;
	system("pause");
}
void truck::set_tow_capacity(int num)
{
	tow_capacity = num;
}
int truck::get_tow_capacity()
{
	return tow_capacity;
}
void truck::set_cab_size(string size)
{
	cab_size = size;
}
string truck::get_cab_size()
{
	return cab_size;
}
void truck::print()
{
	vehicle::print();
	cout << "Truck tow capacity: " << tow_capacity << endl;
	cout << "Truck cab size: " << cab_size << endl << endl << endl;
}
int main()
{
	int choice, option, decision, preference, sold[100], position = 0;
	for (int m = 0; m < 100; m++)
	{
		sold[m] = -1;
	}
	car *library = new car[NUM];
	truck *inventory = new truck[NUM];
	bus *portfolio = new bus[NUM];
	do {
		system("cls");
		cout << "Please enter the number corresponding to your choice:\n\n1:Browse\n2:Transaction\n3:Edit Catalog\n4:Cars Sold\n\n";
		cin >> option;
		if (option == 4)
		{
			system("cls");
			for (int i = 0; i < 100; i++)
			{
				if (sold[i] <= 45864 && sold[i]>-1) {
					library[sold[i] / 936].print();
					cout << endl;
				}
				if (sold[i] > 45864 && sold[i]<93900) {
					inventory[(sold[i] / 936) - NUM].print();
					cout << endl;
				}
				if (sold[i] > 93900) {
					portfolio[(sold[i] / 936) - NUM - NUM].print();
					cout << endl;
				}
			}
		}
		if (option == 1)
		{
			system("cls");
			cout << "Cars:" << endl << endl;
			for (int count = 0; count < NUM; count++)
			{
				if (library[count].get_ID() == -1)
				{
					break;
				}
				library[count].print();
			}
			cout << endl << endl << "Trucks:" << endl << endl;
			for (int count = 0; count < NUM; count++)
			{
				if (inventory[count].get_ID() == -1)
				{
					break;
				}
				inventory[count].print();
			}
			cout << endl << endl << "Buses:" << endl << endl;
			for (int count = 0; count < NUM; count++)
			{
				if (portfolio[count].get_ID() == -1)
				{
					break;
				}
				portfolio[count].print();
			}
		}
		else if (option == 3)
		{
			system("cls");
			cout << "Would you like to add a new Vehicle or Delete one?\n1:New\t2:Delete\n";
			cin >> decision;
			if (decision == 1)
			{
				system("cls");
				cout << "Would you like to add a new Car,Truck or Bus?\n1:Car\t2:Truck\t3:Bus\n";
				cin >> preference;
				if (preference == 1)
				{
					string clr, type;
					int id, num, doors, count, stock;
					for (count = 0; count < NUM; count++)
					{
						if (library[count].get_ID() == -1)
						{
							library[count].set_ID(count * 936);
							break;
						}
					}
					cout << "Please enter the car type: (Toyota/Chevrolet): ";
					cin >> type;
					library[count].set_type(type);
					cout << "Please enter the Model Number of car: ";
					cin >> num;
					library[count].set_model_number(num);
					cout << "\nPlease enter the Color of the car: ";
					cin >> clr;
					library[count].set_color(clr);
					cout << "\nPlease enter the number of doors: ";
					cin >> doors;
					library[count].set_num_of_doors(doors);
					cout << "\nPlease enter stock: ";
					cin >> stock;
					library[count].set_stock(stock);
				}
				else if (preference == 2)
				{
					string clr, cs;
					int id, num, tc, count, stock;
					for (count = 0; count < NUM; count++)
					{
						if (inventory[count].get_ID() == -1)
						{
							inventory[count].set_ID((count + NUM) * 936);
							break;
						}
					}
					cout << "Please enter the Model Number of truck: ";
					cin >> num;
					inventory[count].set_model_number(num);
					cout << "\nPlease enter the Color of the truck: ";
					cin >> clr;
					inventory[count].set_color(clr);
					cout << "\nPlease enter the tow capacity: ";
					cin >> tc;
					inventory[count].set_tow_capacity(tc);
					cout << "\nPlease enter the cab size: ";
					cin >> cs;
					inventory[count].set_cab_size(cs);
					cout << "\nPlease enter stock: ";
					cin >> stock;
					inventory[count].set_stock(stock);
				}
				else if (preference == 3)
				{
					string clr, engine, transmission;
					int id, passengers, count, stock;
					for (count = 0; count < NUM; count++)
					{
						if (portfolio[count].get_ID() == -1)
						{
							portfolio[count].set_ID((count + NUM + NUM) * 936);
							break;
						}
					}
					cout << "\nPlease enter the Color of the truck: ";
					cin >> clr;
					portfolio[count].set_color(clr);
					cout << "\nPlease enter Engine specification: ";
					cin >> engine;
					portfolio[count].set_engine(engine);
					cout << "\nPlease enter transmission: ";
					cin >> transmission;
					portfolio[count].set_transmission(transmission);
					cout << "\nPlease enter Capacity: ";
					cin >> passengers;
					portfolio[count].set_passengers(passengers);
					cout << "\nPlease enter stock: ";
					cin >> stock;
					portfolio[count].set_stock(stock);
				}
			}
			else if (decision == 2)
			{
				int id;
				cout << "Please enter the vehicle ID of the vehicle you want to delete: ";
				cin >> id;
				if (id <= 45864)
				{
					library[id / 936].print();
					library[id / 936].set_ID(-1);
					for (int n = id / 936; n < NUM; n++)
					{
						car temp;
						temp = library[n];
						library[n] = library[n + 1];
						library[n + 1] = temp;
						if (library[n + 1].get_ID() == -1)
						{
							break;
						}
					}
				}
				else if (id > 45864 && id<93900)
				{
					inventory[(id / 936) - NUM].print();
					inventory[(id / 936) - NUM].set_ID(-1);
					for (int n = (id / 936) - NUM; n < NUM; n++)
					{
						truck temp;
						temp = inventory[n];
						inventory[n] = inventory[n + 1];
						inventory[n + 1] = temp;
						if (inventory[n + 1].get_ID() == -1)
						{
							break;
						}
					}
				}
				else if (id >= 93900)
				{
					portfolio[(id / 936) - NUM - NUM].print();
					portfolio[(id / 936) - NUM - NUM].set_ID(-1);
					for (int n = (id / 936) - NUM - NUM; n < NUM; n++)
					{
						bus temp;
						temp = portfolio[n];
						portfolio[n] = portfolio[n + 1];
						portfolio[n + 1] = temp;
						if (portfolio[n + 1].get_ID() == -1)
						{
							break;
						}
					}
				}
			}
		}
		else if (option == 2)
		{
			system("cls");
			int id, mistake, count, check;
			do {
				mistake = 0;
				cout << "Please enter the ID of the vehicle: ";
				cin >> id;
				if (id <= 45864) {
					for (count = 0; count < NUM; count++)
					{
						if ((library[count].get_ID() == id))
						{
							check = 1;
							break;
						}
					}
					if (check == 1)
					{
						int quantity_NUM = 0;
						if (library[count].get_stock() == 0)
						{
							cout << "\nSorry! But this car is out of stock.";
						}
						else {
							system("cls");
							cout << "Car Found!\n";
							library[count].print();
							cout << "\n\nHow many cars would you like to purchase? ";
							do {
								if (quantity_NUM != 0)
								{
									cout << "\nThe number of cars entered is not available! Please enter again or enter -1 to cancel transaction.\n";
								}
								cin >> quantity_NUM;
								if (quantity_NUM == -1)
								{
									break;
								}
							} while (quantity_NUM > library[count].get_stock());
							if (quantity_NUM != -1) {
								sold[position] = id;             //updates the transactions
								position++;
								cout << "\nThank you for shopping at our garage!\nPlease pay the dues at the counter\nDo come again!\nGoodbye!";
								library[count].set_stock(library[count].get_stock() - 1);
							}
						}
					}
					else
					{
						cout << "\nCar not found!";
						cout << "\nEnter again? 1:yes 2:no";
						cin >> choice;
						if (choice == 1)
						{
							mistake = 1;
						}
					}
				}
				if (id > 45864 && id<93900)
				{
					for (count = 0; count < NUM; count++)
					{
						if ((inventory[count].get_ID() == id))
						{
							check = 1;
							break;
						}
					}
					if (check == 1)
					{
						int quantity_NUM = 0;
						if (inventory[count].get_stock() == 0)
						{
							cout << "\nSorry! But this truck is out of stock.";
						}
						else {
							system("cls");
							cout << "truck Found!\n";
							inventory[count].print();
							cout << "\n\nHow many trucks would you like to purchase? ";
							do {
								if (quantity_NUM != 0)
								{
									cout << "\nThe number of trucks entered is not available! Please enter again or enter -1 to cancel transaction.\n";
								}
								cin >> quantity_NUM;
								if (quantity_NUM == -1)
								{
									break;
								}
							} while (quantity_NUM > inventory[count].get_stock());
							if (quantity_NUM != -1) {
								sold[position] = id;             //updates the transactions
								position++;
								cout << "\nThank you for shopping at our garage!\nPlease pay the dues at the counter\nDo come again!\nGoodbye!";
								inventory[count].set_stock(inventory[count].get_stock() - 1);
							}
						}
					}
					else
					{
						cout << "\ntruck not found!";
						cout << "\nEnter again? 1:yes 2:no";
						cin >> choice;
						if (choice == 1)
						{
							mistake = 1;
						}
					}
				}
				else if (id > 93900) {
					for (count = 0; count < NUM; count++)
					{
						if ((portfolio[count].get_ID() == id))
						{
							check = 1;
							break;
						}
					}
					if (check == 1)
					{
						int quantity_NUM = 0;
						if (portfolio[count].get_stock() == 0)
						{
							cout << "\nSorry! But this Bus is out of stock.";
						}
						else {
							system("cls");
							cout << "Bus Found!\n";
							portfolio[count].print();
							cout << "\n\nHow many buses would you like to purchase? ";
							do {
								if (quantity_NUM != 0)
								{
									cout << "\nThe number of buses entered is not available! Please enter again or enter -1 to cancel transaction.\n";
								}
								cin >> quantity_NUM;
								if (quantity_NUM == -1)
								{
									break;
								}
							} while (quantity_NUM > portfolio[count].get_stock());
							if (quantity_NUM != -1) {
								sold[position] = id;             //updates the transactions
								position++;
								cout << "\nThank you for shopping at our garage!\nPlease pay the dues at the counter\nDo come again!\nGoodbye!";
								portfolio[count].set_stock(portfolio[count].get_stock() - 1);
							}
						}
					}
					else
					{
						cout << "\nBus not found!";
						cout << "\nEnter again? 1:yes 2:no";
						cin >> choice;
						if (choice == 1)
						{
							mistake = 1;
						}
					}
				}
			} while (mistake == 1);
		}
		do {
			cout << "\n\nEnter your choice: (1)Main Menu (2)Exit\n";
			cin >> choice;
		} while (choice != 1 && choice != 2);
	} while (choice == 1);
	system("pause");
}   //end main