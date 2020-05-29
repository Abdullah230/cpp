#include <iostream>
using namespace std;
class animal{
private:
	int population;
	double area;
public:
	void set_population(int p){
		if (p < 0){
			population = 0;
		}
		else population = p;
	}
	void set_area(double a){
		if (a < 0){
			area = 0;
		}
		else area = a;
	}

	double get_area(){
		return area;
	}

	double get_population(){
		return population;
	}

	double pop_density(){
		return (population / area);
	}
};
class person {
private:
	double population;
	double area;
public:
	void set_population(int p){
		if (p < 0){
			population = 0;
		}
		else population = p;
	}
	void set_area(double a){
		if (a < 0){
			area = 0;
		}
		else area = a;
	}

	double get_area(){
		return area;
	}

	double get_population(){
		return population;
	}

	double pop_density(){
		return (population / area);
	}
};

int main(){
	animal cat;
	int p, p1;
	double a, a1;
	cout << "Please enter the population of cats: ";
	cin >> p;
	cout << "Please enter the area of residence: ";
	cin >> a;
	cat.set_population(p);
	cat.set_area(a);
	cout << "the population of cats is " << cat.get_population() << "\n";
	cout << "The area of residence of cats is " << cat.get_area() << "\n";
	cout << "The population density of the cats is " << cat.pop_density() << "\n\n";

	person zohair;
	cout << "Please enter the population of people: ";
	cin >> p1;
	cout << "Please enter the area of residence: ";
	cin >> a1;
	zohair.set_population(p1);
	zohair.set_area(a1);
	cout << "the population of people is " << zohair.get_population() << "\n";
	cout << "The area of residence of people is " << zohair.get_area() << "\n";
	cout << "The population density of the people is " << zohair.pop_density() << "\n";

	system("pause");


}