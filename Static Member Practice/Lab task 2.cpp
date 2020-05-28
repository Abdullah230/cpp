#include <iostream>
using namespace std;

class SavingsAccount{
private:
	//declaring variables
	static float annualinterestrate;
	static int counter;
	static int counter2;
	static int counter3;
	float savingsbalance;
public:
	//Set balance function
	void set_balance(){
		float x;
		int number;
		number = counter;
		cout << "Please enter the balance of the account number " << number << " :";
		cin >> x;
		counter++;
		savingsbalance = x;
	}
	//Calculating monthly interest
	void calculatemonthlyinterest(){
		cout << "The monthly interest rate of account number "<< counter2++ <<" is " << (savingsbalance * annualinterestrate) / 12 << endl;
		savingsbalance += (savingsbalance * annualinterestrate) / 12;
		cout << "And the new balance is " << savingsbalance << endl;
	}
	//Changing interest rate
	static void modifyinterestrate(){
		float y;
		cout << "Please enter the new interest rate of account number " << counter3++ <<": ";
		cin >> y;
		annualinterestrate = y;
	}
};
	//Initializing static variables
	float SavingsAccount::annualinterestrate = 0.03;
	int SavingsAccount::counter = 1;
	int SavingsAccount::counter2 = 1;
	int SavingsAccount::counter3 = 1;

	int main(){
		//Creating objects
		SavingsAccount s1, s2;
		//Setting Balance
		s1.set_balance();
		s2.set_balance();
		//Modifying niterest rate
		s1.modifyinterestrate();
		s2.modifyinterestrate();
		//Calculating monthly interest
		s1.calculatemonthlyinterest();
		s2.calculatemonthlyinterest();
		//modifying interest rate
		s1.modifyinterestrate();
		s2.modifyinterestrate();
		//Calculating monthly interest.
		s1.calculatemonthlyinterest();
		s2.calculatemonthlyinterest();

	}