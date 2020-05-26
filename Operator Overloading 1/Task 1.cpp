#include <iostream>
using namespace std;

class Polynomial{
private:
	int cons, fdc, sdc;

	

public:

	Polynomial(int a = 0, int b = 0, int c = 0){
		this->cons = a;
		this->fdc = b;
		this->sdc = c;
	}

	friend ostream &operator<<(ostream& output, const Polynomial& p1){
		if (p1.sdc!= 0 && p1.fdc > 0 && p1.cons > 0){
			output << p1.sdc << "x^2 + " << p1.fdc << "x + " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc < 0 && p1.cons > 0){
			output << p1.sdc << "x^2 " << p1.fdc << "x + " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc > 0 && p1.cons < 0){
			output << p1.sdc << "x^2 + " << p1.fdc << "x " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc < 0 && p1.cons < 0){
			output << p1.sdc << "x^2 " << p1.fdc << "x " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc == 0 && p1.cons < 0){
			output << p1.sdc << "x^2 " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc == 0 && p1.cons > 0){
			output << p1.sdc << "x^2 + " << p1.cons;
		}

		else if (p1.sdc != 0 && p1.fdc > 0 && p1.cons == 0){
			output << p1.sdc << "x^2 + " << p1.fdc << "x";
		}

		else if (p1.sdc != 0 && p1.fdc < 0 && p1.cons == 0){
			output << p1.sdc << "x^2 " << p1.fdc << "x";
		}

		else if (p1.sdc == 0 && p1.fdc > 0 && p1.cons > 0){
			output << p1.fdc << "x + " << p1.cons;
		}

		else if (p1.sdc == 0 && p1.fdc > 0 && p1.cons < 0){
			output << p1.fdc << "x " << p1.cons;
		}

		else if (p1.sdc == 0 && p1.fdc < 0 && p1.cons > 0){
			output << p1.fdc << "x + " << p1.cons;
		}

		else if (p1.sdc == 0 && p1.fdc < 0 && p1.cons < 0){
			output << p1.fdc << "x " << p1.cons;
		}

		else if (p1.sdc == 0 && p1.fdc == 0 && p1.cons == 0){
			output << p1.sdc << "x^2 + " << p1.fdc << "x + " << p1.cons;
		}

		return output;

	}

	void set_constant(){
		int cons;
		cout << "Please enter the constant";
		cin >> cons;
		this->cons = cons;
	}

	void set_fdc(){
		int fdc;
		cout << "Please enter the multiplier of the first variable";
		cin >> fdc;
		this->fdc = fdc;
	}

	void set_sdc(){
		int sdc;
		cout << "Please enter the multiplier of the second degree";
		cin >> sdc;
		this->sdc = sdc;
	}

	void operator+(const Polynomial& o){
		this->sdc = this->sdc + o.sdc;
		this->fdc = this->fdc + o.fdc;
		this->cons = this->cons + o.cons;
	}

	void operator-(const Polynomial& o){
		this->sdc = this->sdc - o.sdc;
		this->fdc = this->fdc - o.fdc;
		this->cons = this->cons - o.cons;
	}
	

};

int main(){
	Polynomial p1, p2(2,3,4);
	int user;
	cout << "Please input 1 to change the values of p2 or press another key to continue";
	cin >> user;
	if (user == 1){
		p2.set_sdc();
		p2.set_fdc();
		p2.set_constant();
	}
	cout << "Adding p2 to p1" << endl;
	p1 + p2;
	cout << "Adding p2 again" << endl;
	p1 + p2;
	cout << "Now printing" << endl;
	cout << p1 << endl;
	cout << "Now subtracting p2 from p1" << endl;
	p1 - p2;
	cout << "Printing p1" << endl;
	cout << p1;
	system("pause");
	return 0;

}